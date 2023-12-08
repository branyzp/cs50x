#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    //* initialize integer startPop as the starting population size and endPop as the ending population size
    int startPop;
    int endPop;
    int born;
    int die;
    int years = 0;

    // * do while loop to force the user to input a positive integer higher than 9
    do
    {
        startPop = get_int("Starting Population Size: ");
    }
    while (startPop > 0 && startPop < 9);

    // TODO: Prompt for end size
    // * do while loop to force the user to input a positive integer equal to or higher than the starting population size

    do
    {
        endPop = get_int("Ending Population Size: ");
    }
    while (endPop > 0 && endPop <= startPop);

    // TODO: Calculate number of years until we reach threshold
    // * need a counter named years to increment
    // * do-while loop again to incrementally add babies born and minus people who died, then if the number has not hit the end population size, add 1 to years
    do
    {
        // born = startPop / 3;
        // die = startPop / 4;
        // startPop += born;
        // startPop -= die;

        // * shorten the code
        startPop += (startPop / 3) - (startPop / 4);

        // * this is just to display the difference in the number in the console
        printf("Year %d: %d \n", years, startPop);
        if (startPop <=endPop)
        {
            years++;
        }
    }
    while (startPop <= endPop);

    // TODO: Print number of years
    printf("Years: %d \n", years);
}

