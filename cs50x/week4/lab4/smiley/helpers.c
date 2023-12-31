#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing

    // * in order to change the black pixels to a color, we need to be able to manipulate the
    // * RGB values of the outfile
    // * we can try a nested for loop to manipulate the image[height][width]

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            image[i][k].rgbtGreen = 255;
            image[i][k].rgbtBlue = 255;
            image[i][k].rgbtRed = 255;
        }
    }
}
