//
//  Image.h
//  EngineTest
//
//  Created by Chase Bradbury on 2/23/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__Image__
#define __EngineTest__Image__

#include <iostream>
#include <fstream>
#include "Pixel.h"

using namespace std;

typedef unsigned int pixel_t;

class Image {
private:
    int width;
    int height;
    int size;
    int* pixels;
    bool grayscale;
    
public:
    Image(char* filename);
    
    
    
    int getWidth();
    
    int getHeight();
    
    int getPixel(int x, int y);
    
    int getRedValue(int x, int y);
    
    int getGreenValue(int x, int y);
    
    int getBlueValue(int x, int y);
    
    int getAlphaValue(int x, int y);
    
    bool isGrayscale();
    
    
    
    void LoadPPM(char* filename);
    
    void savePPM(char* filename);
    
    void setPixel(int x, int y, int pixel);
    
    void setPixel(int x, int y, int red, int green, int blue, int alpha);
    
    void setRedValue(int x, int y, int red);
    
    void setGreenValue(int x, int y, int green);
    
    void setBlueValue(int x, int y, int blue);
    
    void setAlphaValue(int x, int y, int alpha);
    
    void invert();
    
    
    
    Image operator +(Image);
    Image operator -(Image);
    Image operator *(Image);
    Image operator &(Image);
};

#endif /* defined(__EngineTest__Image__) */
