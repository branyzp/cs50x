#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // * loop over all pixels using 2d array
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // * take average of r,g,b
            float avgrgb = round((image[i][k].rgbtRed + image[i][k].rgbtBlue + image[i][k].rgbtGreen) / 3.0);
            // * update pixel values
            image[i][k].rgbtRed = avgrgb;
            image[i][k].rgbtBlue = avgrgb;
            image[i][k].rgbtGreen = avgrgb;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // * Compute sepia values
            float sepiaRed = round(.393 * image[i][k].rgbtRed + .769 * image[i][k].rgbtGreen + .189 * image[i][k].rgbtBlue);
            float sepiaGreen = round(.349 * image[i][k].rgbtRed + .686 * image[i][k].rgbtGreen + .168 * image[i][k].rgbtBlue);
            float sepiaBlue = round(.272 * image[i][k].rgbtRed + .534 * image[i][k].rgbtGreen + .131 * image[i][k].rgbtBlue);

            // * to check if each of the sepia color values are more than 255, and if so, to make them 255 at max
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            // * Update pixel with sepia values
            image[i][k].rgbtRed = sepiaRed;
            image[i][k].rgbtBlue = sepiaBlue;
            image[i][k].rgbtGreen = sepiaGreen;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // * loop over all pixels
        for (int k = 0; k < (width / 2); k++)
        {
            // * swap pixels
            RGBTRIPLE temp = image[i][k];
            image[i][k] = image[i][width - (k + 1)];
            image[i][width - (k + 1)] = temp;
        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // * Create a copy of image
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            copy[i][k] = image[i][k];
            // * use the copy 2d array for reading and image 2d array for changing
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int k = 0; k < width; k++)
        {
            // * declare the required variables
            // * pixelCnt is the count of surrounding pixels to the current pixel, so that we can divide to find the average later
            // on
            float pixelCnt = 0;

            // * these are the average of each Blue, Red and Green, initially are 0
            int avgB, avgR, avgG;
            avgB = avgR = avgG = 0;

            // * loop through the upper and side pixels adjacent to the current pixel
            for (int a = (i - 1); a < (i + 2); a++)
            {
                for (int b = (k - 1); b < (k + 2); b++)
                {
                    // * check that the surrounding pixels do not go out of bounds
                    if ((a > -1 && a < height) && (b > -1 && b < width))
                    {
                        avgB += copy[a][b].rgbtBlue;
                        avgR += copy[a][b].rgbtRed;
                        avgG += copy[a][b].rgbtGreen;
                        pixelCnt++;
                    }
                }
            }
            image[i][k].rgbtBlue = round(avgB / pixelCnt);
            image[i][k].rgbtRed = round(avgR / pixelCnt);
            image[i][k].rgbtGreen = round(avgG / pixelCnt);
        }
    }

    return;
}
