#include "helpers.h"
#include <stdbool.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width]) {
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      float average = (float)(image[i][j].rgbtRed + image[i][j].rgbtBlue +
                              image[i][j].rgbtGreen) /
                          3 +
                      0.5;
      image[i][j].rgbtGreen = (int)average;
      image[i][j].rgbtRed = (int)average;
      image[i][j].rgbtBlue = (int)average;
    }
  }
  return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width]) {

  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      int red = image[i][j].rgbtRed;
      int green = image[i][j].rgbtGreen;
      int blue = image[i][j].rgbtBlue;

      float sepiaRed = (.393 * red + .769 * green + .189 * blue) + 0.5;
      float sepiaGreen = (.349 * red + .686 * green + .168 * blue) + 0.5;
      float sepiaBlue = (.272 * red + .534 * green + .131 * blue) + 0.5;

      image[i][j].rgbtRed = sepiaRed > 255 ? 255 : (int)sepiaRed;
      image[i][j].rgbtGreen = sepiaGreen > 255 ? 255 : (int)sepiaGreen;
      image[i][j].rgbtBlue = sepiaBlue > 255 ? 255 : (int)sepiaBlue;
    }
  }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width]) {
  int middle = width / 2;
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < middle; j++) {
      RGBTRIPLE pixel = image[i][j];
      image[i][j] = image[i][width - j - 1];
      image[i][width - j - 1] = pixel;
    }
  }
  return;
}
RGBTRIPLE get_average_pixel(int height, int width,
                            RGBTRIPLE copy[height][width], int heightIndex,
                            int widthIndex) {
  RGBTRIPLE averagePixel = {0, 0, 0};

  int sumRed = 0;
  int sumGreen = 0;
  int sumBlue = 0;

  int count = 0;

  for (int i = heightIndex - 1; i <= heightIndex + 1; i++) {
    for (int j = widthIndex - 1; j <= widthIndex + 1; j++) {
      if (i >= 0 && i < height && j >= 0 && j < width) {
        sumRed += copy[i][j].rgbtRed;
        sumGreen += copy[i][j].rgbtGreen;
        sumBlue += copy[i][j].rgbtBlue;
        count++;
      }
    }
  }

  averagePixel.rgbtRed = (int)(sumRed / (double)count + 0.5);
  averagePixel.rgbtGreen = (int)(sumGreen / (double)count + 0.5);
  averagePixel.rgbtBlue = (int)(sumBlue / (double)count + 0.5);
  return averagePixel;
}
// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width]) {
  RGBTRIPLE copy[height][width];
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      copy[i][j] = image[i][j];
    }
  }
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      image[i][j] = get_average_pixel(height, width, copy, i, j);
    }
  }
  return;
}
