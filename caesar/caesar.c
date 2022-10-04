#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool check_key(string s);
char encrypt(int key, char input);

int main(int argc, string argv[])
{

    // printf("%c\n", argv[1]);
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        if (check_key(argv[1]) == false)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
        else
        {
            int key = atoi(argv[1]);
            string plaintext = get_string("plaintext: ");
            printf("ciphertext: ");
            for (int i = 0, n = strlen(plaintext); i < n; i++)
            {
                printf("%c", encrypt(key, plaintext[i]));
            }
            printf("\n");
        }
    }
}

bool check_key(string s)
{
    int count = 0;
    //printf("test input string: %s \n", s);
    //for (int i = strlen(s); i >= 0; i--)
    for (int i = 0; i < strlen(s); i++)
    {
        if (isdigit(s[i]) != 0)
        {
            //printf("%c \n", s[i]);
            count++;
        }
    }
    if (count == strlen(s))
    {
        return true;
    }
    else
    {
        return false;
    }
    //printf("counter test: %i\n", count);
    //return false;
}

char encrypt(int key, char input)
{
    char output;

    if (islower(input))
    {
        //97 is ascii lower case 'a' value
        output = (((input + key) - 97) % 26) + 97;
    }
    else if (isupper(input))
    {
        //65 is ascii upper case 'A' value
        output = (((input + key) - 65) % 26) + 65;
    }
    else
    {
        output = input;
    }

    return output;
}
