#include "helpers.h"
#include <stdio.h>
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
                int average;
                average = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
                image[i][j].rgbtBlue = average;
                image[i][j].rgbtGreen = average;
                image[i][j].rgbtRed = average;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int middlePosition = width / 2;

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < middlePosition; j++) {
                RGBTRIPLE tmp;

                tmp = image[i][width - j - 1];
                image[i][width - j - 1] = image[i][j];
                image[i][j]= tmp;
            }
        }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE tempArray[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            tempArray[i][j].rgbtBlue = 0;
            tempArray[i][j].rgbtGreen = 0;
            tempArray[i][j].rgbtRed = 0;
        }
    }

    for (int verticle = 0; verticle < height; verticle++) {
        for (int horizen = 0; horizen < width; horizen++) {
            float sumBlue = 0, sumGreen = 0, sumRed = 0;
            int count = 0;

            for (int i = verticle - 1; i <= verticle + 1; i++) {
                for (int j = horizen - 1; j <= horizen + 1; j++) {
                    if (i < 0 || j < 0 || i >= height || j >= width) {
                        continue;
                    }
                    sumBlue += image[i][j].rgbtBlue;
                    sumGreen += image[i][j].rgbtGreen;
                    sumRed += image[i][j].rgbtRed;
                    count++;
                }
            }

            tempArray[verticle][horizen].rgbtBlue = round(sumBlue / count);
            tempArray[verticle][horizen].rgbtGreen = round(sumGreen / count);
            tempArray[verticle][horizen].rgbtRed = round(sumRed / count);
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtBlue = tempArray[i][j].rgbtBlue;
            image[i][j].rgbtGreen = tempArray[i][j].rgbtGreen;
            image[i][j].rgbtRed = tempArray[i][j].rgbtRed;
        }
    }


    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE sobel[height][width];

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            sobel[i][j].rgbtBlue = 0;
            sobel[i][j].rgbtRed = 0;
            sobel[i][j].rgbtGreen = 0;
        }
    }

    for (int targetHeight = 0; targetHeight < height; targetHeight++) {
        for (int targetWidth = 0; targetWidth < width; targetWidth++) {

        // declare and reset Gx Gy after sobel-calculating is done.
        int sumGxblue = 0, sumGxred = 0, sumGxgreen = 0;
        int sumGyblue = 0, sumGyred = 0, sumGygreen = 0;
        int sobelBlue = 0, sobelRed = 0, sobelGreen = 0;

            // calculate Gx Gy for sobel
            for (int i = targetHeight - 1; i <= targetHeight + 1; targetHeight++) {
                for (int j = targetWidth - 1; j <= targetWidth + 1; targetWidth++) {
                    // Gx, Gy over margin is 0.
                    if (i < 0 || j < 0 || i >= height || j >= width) {
                        continue;
                    } else {
                        // up left
                        if (i == targetHeight - 1 && j == targetWidth - 1) {
                            sumGxblue += image[i][j].rgbtBlue * -1;
                            sumGxred += image[i][j].rgbtRed * -1;
                            sumGxgreen += image[i][j].rgbtGreen * -1;

                            sumGyblue += image[i][j].rgbtBlue * -1;
                            sumGyred += image[i][j].rgbtRed * -1;
                            sumGygreen += image[i][j].rgbtGreen * -1;

                        // left
                        } else if (i == targetHeight && j == targetWidth - 1) {
                            sumGxblue += image[i][j].rgbtBlue * -1;
                            sumGxred += image[i][j].rgbtRed * -1;
                            sumGxgreen += image[i][j].rgbtGreen * -1;

                        // bottom left
                        } else if (i == targetHeight + 1 && j == targetWidth - 1) {
                            sumGxblue += image[i][j].rgbtBlue * -1;
                            sumGxred += image[i][j].rgbtRed * -1;
                            sumGxgreen += image[i][j].rgbtGreen * -1;

                            sumGyblue += image[i][j].rgbtBlue * 1;
                            sumGyred += image[i][j].rgbtRed * 1;
                            sumGygreen += image[i][j].rgbtGreen * 1;

                        // up
                        } else if (i == targetHeight - 1 && j == targetWidth) {
                            sumGyblue += image[i][j].rgbtBlue * -2;
                            sumGyred += image[i][j].rgbtRed * -2;
                            sumGygreen += image[i][j].rgbtGreen * -2;

                        // down
                        } else if (i == targetHeight + 1 && j == targetWidth) {
                            sumGyblue += image[i][j].rgbtBlue * 2;
                            sumGyred += image[i][j].rgbtRed * 2;
                            sumGygreen += image[i][j].rgbtGreen * 2;

                        // up right
                        } else if (i == targetHeight - 1 && j == targetWidth + 1) {
                            sumGxblue += image[i][j].rgbtBlue * 1;
                            sumGxred += image[i][j].rgbtRed * 1;
                            sumGxgreen += image[i][j].rgbtGreen * 1;

                            sumGyblue += image[i][j].rgbtBlue * -1;
                            sumGyred += image[i][j].rgbtRed * -1;
                            sumGygreen += image[i][j].rgbtGreen * -1;

                        // right
                        } else if (i == targetHeight && j == targetWidth + 1) {
                            sumGxblue += image[i][j].rgbtBlue * 2;
                            sumGxred += image[i][j].rgbtRed * 2;
                            sumGxgreen += image[i][j].rgbtGreen * 2;

                        // bottom right
                        } else if (i == targetHeight && j == targetWidth + 1) {
                            sumGxblue += image[i][j].rgbtBlue * 1;
                            sumGxred += image[i][j].rgbtRed * 1;
                            sumGxgreen += image[i][j].rgbtGreen * 1;

                            sumGyblue += image[i][j].rgbtBlue * 1;
                            sumGyred += image[i][j].rgbtRed * 1;
                            sumGygreen += image[i][j].rgbtGreen * 1;
                        }
                    }
                }
            }

        // calculate sobel for each pixel
        sobelBlue = round(sqrt(sumGxblue * sumGxblue + sumGyblue * sumGyblue));
        sobelRed = round(sqrt(sumGxred * sumGxred + sumGyblue * sumGyblue));
        sobelGreen = round(sqrt(sumGxgreen * sumGxgreen + sumGygreen * sumGygreen));

        // if sobel beyound the scope, set it as 255
        if (sobelBlue > 255) {
            sobelBlue = 255;
        }

        if (sobelRed > 255) {
            sobelRed = 255;
        }

        if (sobelGreen > 255) {
            sobelGreen = 255;
        }

        // temparaily save sobel in sobelArray
        sobel[targetHeight][targetWidth].rgbtBlue = sobelBlue;
        sobel[targetHeight][targetWidth].rgbtRed = sobelRed;
        sobel[targetHeight][targetWidth].rgbtGreen = sobelGreen;
        
        printf("sobelblue:%d, sobelRed:%d, sobelGreen:%d", sobelBlue, sobelRed, sobelGreen);
        }
    }

    // change RGB of every pixel
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            image[i][j].rgbtBlue = sobel[i][j].rgbtBlue;
            image[i][j].rgbtRed = sobel[i][j].rgbtRed;
            image[i][j].rgbtGreen = sobel[i][j].rgbtGreen;
        }
    }
    return;
}
