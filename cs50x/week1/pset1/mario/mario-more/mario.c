#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // * initialise all the required variables here
    int height;

    // * first, we need a prompt for user for a positive integer between 1 to 8 inclusive
    do
    {
        height = get_int("What height should the pyramid be? Between 1 and 8 inclusive please. :");
    }
    while (height < 1 || height > 8);

    // * next, we need a loop that will output the hashes in rows
    // * we also need a loop that will be able to add hashes according to the height and the middle 2 spaces
    for (int i = 2; i < height+2; i++)
    {
        for(int k = height; k > i-1; k--)
        {
            printf(" ");
        }
        for (int j = 1; j < i; j++)
        {
            printf("#");
        }

        printf("  ");


        // for(int m = height; m > i-1; m--)
        // {
        //     printf(" ");
        // }
        for (int n = 1; n < i; n++)
        {
            printf("#");
        }
        printf("\n");
    }
}

