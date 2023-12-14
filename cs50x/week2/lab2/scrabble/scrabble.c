#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // printf("score1: %i\n", score1);
    // printf("score2: %i\n", score2);
    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    int score = 0;
    // TODO: Compute and return score for string
    // * create array of alphabet to correspond to the POINTS[] array
    int ALPHABET[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                      'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    // * iterate through the string word, char by char
    for (int i = 0, wordLength = strlen(word); i < wordLength; i++)
    {
        // * lowercase the char immediately
        char currentChar = tolower(word[i]);
        // printf("currentChar: %c\n", currentChar);
        for (int a = 0, arrLen = 27; a < arrLen; a++)
        {
            if (currentChar == ALPHABET[a])
            {
                score += POINTS[a];
            }
        }
    }
    return score;
}
