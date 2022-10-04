#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    //check vaild input
    if (argc != 2)
    {
        printf("Usage: ./recover IMAGE\n");
        return 1;
    }
    //open input file, check for content
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    //make oupt file
    FILE *output = NULL;
    //initialise useful variables
    BYTE jpg[512];
    char filename[8];
    int jpegs = 0;

    while (fread(jpg, sizeof(BYTE), 512, input) == 512)\
    {
        //checkl for JPG conditions
        if (jpg[0] == 0xff && jpg[1] == 0xd8 && jpg[2] == 0xff && (jpg[3] & 0xf0) == 0xe0)
        {
            //writes data to output file, checks if first image or not
            if (jpegs == 0)
            {
                sprintf(filename, "%03i.jpg", jpegs);
                output = fopen(filename, "w");
                fwrite(&jpg, sizeof(BYTE), 512, output);
                jpegs++;
            }
            else if (jpegs > 0)
            {
                fclose(output);
                sprintf(filename, "%03i.jpg", jpegs);
                output = fopen(filename, "w");
                fwrite(&jpg, sizeof(BYTE), 512, output);
                jpegs++;
            }
        }
        else if (jpegs > 0)
        {
            //continutes write operation in event of no new JPG file
            fwrite(&jpg, sizeof(BYTE), 512, output);
        }
    }
    //close all
    fclose(input);
    fclose(output);
}