#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_scentances(string text);

int main(void)
{
    string words = get_string("Text: ");
    double letter = count_letters(words);
    double word = count_words(words);
    double scentance = count_scentances(words);

    double L = letter / word * 100;
    double S = scentance / word * 100;

    //printf("scentance count test: %d \n", scentance/word);
    //printf("letter count test: %d \n", L);
    double index = 0.0588 * L - 0.296 * S - 15.8;
    //double in = index;
    int grade = round(index);
    //check for grade levels
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        // printf("Grade %i \n", grade);
        printf("Grade %i\n", grade);
    }
    /*
    printf("%f letters \n", letter);
    printf("%f words \n", word);
    printf("%f scentances \n", scentance);
    printf("%f index \n", index);
    printf("%f letters/100 words \n", L);
    printf("%f scentances/100 words \n", S);
    printf("%i grade \n", grade);
    */
}

int count_letters(string text)
{
    int letters = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
    }
    //printf("letter check: %i \n", letters);
    return letters;
}

int count_words(string text)
{
    int words = 1;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }
    //printf("word check: %i \n", words);
    return words;
}

int count_scentances(string text)
{
    int counter = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (text[i] == '.')
        {
            counter++;
            // printf("test1 \n");
        }
        else if (text[i] == '!')
        {
            counter++;
            // printf("test2 \n");
        }
        else if (text[i] == '?')
        {
            counter++;
            // printf("test3 \n");
        }
    }
    //printf("scentance check: %i \n", counter);
    return counter;
}