#include "helpers.h"
#include <math.h>
int limit(int value)
{
    if (value > 255)
    {
        return 255;
    }
    else if (value < 0)
    {
        return 0;
    }
    return value;
}
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int media = (int) round(
                (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = media;
            image[i][j].rgbtRed = media;
            image[i][j].rgbtGreen = media;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed =
                limit((int) round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen +
                                  .189 * image[i][j].rgbtBlue));
            int sepiaGreen =
                limit((int) round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen +
                                  .168 * image[i][j].rgbtBlue));
            int sepiaBlue =
                limit((int) round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen +
                                  .131 * image[i][j].rgbtBlue));

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {

            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE matrizCopia[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            matrizCopia[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int avgR = 0, avgG = 0, avgB = 0, counter = 0;

            for (int row = -1; row <= 1; row++)
            {
                for (int column = -1; column <= 1; column++)
                {
                    int newRow = i + row;
                    int newCol = j + column;

                    if (newRow >= 0 && newRow < height && newCol >= 0 && newCol < width)
                    {
                        avgR += matrizCopia[newRow][newCol].rgbtRed;
                        avgG += matrizCopia[newRow][newCol].rgbtGreen;
                        avgB += matrizCopia[newRow][newCol].rgbtBlue;
                        counter++;
                    }
                }
            }

            image[i][j].rgbtRed = round(avgR / (float) counter);
            image[i][j].rgbtGreen = round(avgG / (float) counter);
            image[i][j].rgbtBlue = round(avgB / (float) counter);
        }
    }
}
