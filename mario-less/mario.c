#include <cs50.h>
#include <stdio.h>

void pyramid(int height);
int main(void)
{
    int height;

    do
    {
        height = get_int("Height: "); //set height of pyramid
    }
    while (height < 1 || height > 8);
    {
        pyramid(height); //build pyramid
    }
}

void pyramid(int height) //building pyramid function
{
    for (int i = 0; i < height; i++)
    {
        for (int j = height - i; j > 1; j--)
        {
            printf(" ");
        }

        for (int k = 0; k <= i; k++)
        {
            printf("#");
        }
        printf("\n");
    }
}