#include "helpers.h"
#include "math.h"
#include "string.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            //Get RGB values from image
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            //Average RGB Values
            int averageRGB = round((red + green + blue) / 3.0);

            //Update image with average RGB values
            image[i][j].rgbtRed = averageRGB;
            image[i][j].rgbtGreen = averageRGB;
            image[i][j].rgbtBlue = averageRGB;
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
            //Get RGB values
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;

            //Find Sepia Values
            int sepiaRed = round(0.393 * red + 0.769 * green + 0.189 * blue);
            int sepiaGreen = round(0.349 * red + 0.686 * green + 0.168 * blue);
            int sepiaBlue = round(0.272 * red + 0.534 * green + 0.131 * blue);

            //Update Image
            image[i][j].rgbtRed = fmin(255, sepiaRed);
            image[i][j].rgbtGreen = fmin(255, sepiaGreen);
            image[i][j].rgbtBlue = fmin(255, sepiaBlue);
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    //Tempory storage
    RGBTRIPLE store[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            //swap pixels and update image
            store[i][j] = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = store[i][j];
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Temp storage and clone into storage
    RGBTRIPLE clone[height][width];
    memcpy(clone, image, sizeof(RGBTRIPLE) * height * width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float average = 0.0;
            int red = 0;
            int green = 0;
            int blue = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (i + k != height && i + k != -1 && j + l != width && j + l != -1)
                    {
                        //Get average RGB values from clone
                        red += clone[i + k][j + l].rgbtRed;
                        green += clone[i + k][j + l].rgbtGreen;
                        blue += clone[i + k][j + l].rgbtBlue;
                        average++;
                    }
                }
            }
            //update image
            image[i][j].rgbtRed = round(red / average);
            image[i][j].rgbtGreen = round(green / average);
            image[i][j].rgbtBlue = round(blue / average);
        }
    }
}
