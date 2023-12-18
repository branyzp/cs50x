#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int letters;
int words = 1;
int sentences;
float L = 0;
float S = 0;
int index = 0;
int count_letters(string text);

int main(void)
{

    // * let's get the input from the user first
    string text = get_string("Text: ");
    count_letters(text);

    // * the algorithm is index = 0.0588 * L - 0.296 * S - 15.8
    // * where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words
    // in the text.
}
// * first step is to figure out how to determine what is a word and what is a sentence.
// * we need to essentially iterate through each individual char, with a counter for letters, another counter for words and another
// for sentences
// * the counter for letters will ++ whenever there is a letter, and the counter for words will ++ whenever there is a space
// encountered as
// * the end of the word. The counter for sentences will ++ whenever there is a '.', '!' or '?'.
// * let's start

//* add a function to count the letters in the text
int count_letters(string text)
{
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        if (isalpha(text[i]))
        {
            letters++;
        }
        else if (text[i] == ' ')
        {
            words++;
        }
        else if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }
    // printf("letters: %i\n", letters);
    // printf("words: %i\n", words);
    // printf("sentences: %i\n", sentences);

    // * using typecasting here will enable C to perform float division instead of integer division
    // * this will lead to a more precise division
    // * if using int division, 7 divided by 2 = 3 which is inconsistent
    L = (letters * 100 / (float) words);
    S = (sentences * 100 / (float) words);
    // printf("L: %f\n", L);
    // printf("S: %f\n", S);
    index = round(0.0588 * L - 0.296 * S - 15.8);

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
        printf("Grade %i\n", index);
    }

    return true;
}
