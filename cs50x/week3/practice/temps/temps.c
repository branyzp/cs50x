// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(void);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities();

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(void)
{
    // Add your code here
    // * using bubble sort to try out

    // * bubble sort is a sorting algorithm that will traverse the array from left to right
    // * and move the higher values to the right and lower values to the left through swapping

    // * so we will initialise 3 variables - n, m and o, the purpose of these variables is to swap around the elements in the array
    int m, n;
    avg_temp o;
    // * we will also initialise the boolean swapped, to check for the last case of when there is nothing swapped, we can exit the
    // loop
    bool swapCount;
    int templength = 9;
    // * reset swap counter to 0
    // * compare each adjacent pair
    // * if the adjacent pair is not in order, swap them and add 1 to swap counter

    // * first for-loop to iterate through the array
    for (m = 0; m < templength; m++)
    {
        swapCount = 0;
        for (n = 0; n < templength; n++)
        {
            if (temps[n].temp < temps[n + 1].temp)
            {
                // * swap the values
                o = temps[n];
                temps[n] = temps[n + 1];
                temps[n + 1] = o;
                swapCount++;
            }
        }
        if (swapCount == 0)
        {
            break;
        }
    }
}
