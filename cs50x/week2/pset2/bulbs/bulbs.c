#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
int decimal_to_binary(int ascii);

int main(void)
{
    // TODO
    // * get user input
    string message = get_string("Message: ");

    // * break the string down into individual letters, spaces and punctuation using a for-loop
    for (int i = 0, n = strlen(message); i < n; i++)
    {
        int BITS[8] = {0, 0, 0, 0, 0, 0, 0, 0};
        // * convert the letter into ASCII value
        int ascii = (int) message[i];
        // * convert the ASCII value into binary
        // * recursion?
        for (int k = 0; ascii > 0; k++)
        {
            BITS[k] = ascii % 2;
            ascii = ascii / 2;
        }

        for (int l = 7; l >= 0; l--)
        {
            print_bulb(BITS[l]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
