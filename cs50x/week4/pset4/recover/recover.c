#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // * Accept a single command-line argument
    if (argc != 2)
    {
        printf("Usage: ./recover FILENAME\n");
        return 1;
    }

    // * Open the memory card

    FILE *card = fopen(argv[1], "r");
    if (card == NULL)
    {
        printf("File cannot be opened or there is no such file.\n");
    }

    // * Create a buffer for a block of data
    uint8_t buffer[512];

    FILE *newFile = NULL;

    // * string for the filename
    char filename[8];

    // * counter for the filename tracking
    int count = 0;

    while (fread(buffer, sizeof(uint8_t), 512, card) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", count); // for creating a new file

            if (newFile != NULL)
            {
                fclose(newFile);
            }
            newFile = fopen(filename, "w");
            count++;
        }
        if (newFile != NULL)
        {
            fwrite(buffer, sizeof(uint8_t), 512, newFile);
        }
    }
    // Close files
    fclose(card);
    fclose(newFile);
    return 0;
}
