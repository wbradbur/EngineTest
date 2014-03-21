//
//  Image.cpp
//  EngineTest
//
//  Created by Chase Bradbury on 2/23/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#include "Image.h"



Image::Image(char* filename)
{
    LoadPPM(filename);
}



int Image::getWidth()
{
    return width;
}

int Image::getHeight()
{
    return height;
}

int Image::getPixel(int x, int y)
{
    return pixels[x + width * y];
}

int Image::getAlphaValue(int x, int y)
{
    return pixels[x + width * y]>>24 & 0xFF;
}

int Image::getBlueValue(int x, int y)
{
    return pixels[x + width * y]>>16 & 0xFF;
}

int Image::getGreenValue(int x, int y)
{
    return pixels[x + width * y]>>8 & 0xFF;
}

int Image::getRedValue(int x, int y)
{
    return pixels[x + width * y] & 0xFF;
}

bool Image::isGrayscale()
{
    return grayscale;
}



void Image::LoadPPM(char* filename)
{
    FILE *fp;
	int *buf;
    
    if ((fp = fopen(filename, "rb")) == NULL) {
		cout << "Unable to open file" << endl;
    }
    
    fscanf(fp, "P6\n");
    fscanf(fp, "#%*[^\n]\n");
    fscanf(fp, "%d", &width);
    fscanf(fp, "%d", &height);
    fscanf(fp, "%*d\n");
    
    size = width * height;
    pixels = (int *) malloc(size * sizeof(int));
    
    buf = pixels;
    for (int i = 0; i < size; i++, buf++) {
		fread(buf, 1, 3, fp);
        //setAlphaValue(i, 255);
    }
}

void Image::savePPM(char* filename)
{
    FILE *fp;
    //int width, height, size,  i;
    int *buf;
    char data[1];
    
    if ((fp = fopen(filename, "w")) == NULL) {
		cout << "Unable to open file" << endl;
    }
    
    fprintf(fp, "P6\n");
    fprintf(fp, "# Comment Line\n");
    fprintf(fp, "%d %d\n", width, height);
    fprintf(fp, "255\n");
    
    buf = pixels;
    for (int i = 0; i < size; i++, buf++) {
        data[0] = (*buf) & 0xff;
        fwrite(data, 1, 1, fp);
        data[0] = ((*buf) >> 8) & 0xff;
        fwrite(data, 1, 1, fp);
        data[0] = ((*buf) >> 16) & 0xff;
        fwrite(data, 1, 1, fp);
    }
    
    fclose(fp);
}

void Image::setPixel(int x, int y, int pixel)
{
    pixels[x + width * y] = pixel;
}

void Image::setPixel(int x, int y, int red, int green, int blue, int alpha)
{
    pixels[x + width * y] = (alpha<<24) + (blue<<16) + (green<<8) + red;
}

void Image::setAlphaValue(int x, int y, int alpha)
{
    pixels[x + width * y] = (pixels[x + width * y] & 0x00FFFFFF) + (alpha<<24);
}

void Image::setBlueValue(int x, int y, int blue)
{
    pixels[x + width * y] = (pixels[x + width * y] & 0xFF00FFFF) + (blue<<16);
}

void Image::setGreenValue(int x, int y, int green)
{
    pixels[x + width * y] = (pixels[x + width * y] & 0xFFFF00FF) + (green<<8);
}

void Image::setRedValue(int x, int y, int red)
{
    pixels[x + width * y] = (pixels[x + width * y] & 0xFFFFFF00) + (red);
}

void Image::invert()
{
    
}