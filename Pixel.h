//
//  Pixel.h
//  EngineTest
//
//  Created by Chase Bradbury on 2/23/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__Pixel__
#define __EngineTest__Pixel__

#include <iostream>

class Pixel {
private:
    int color;
    
public:
    Pixel(char gray);
    
    Pixel(char red, char green, char blue, char alpha);
    
    Pixel(int allChannels);
    
    char getRedValue();
    
    char getGreenValue();
    
    char getBlueValue();
    
    char getAlphaValue();
    
    int getRedValueInt();
    
    int getGreenValueInt();
    
    int getBlueValueInt();
    
    int getAlphaValueInt();
    
    bool isGrayscale();
    
    void setValues(char gray);
    
    void setValues(char red, char green, char blue, char alpha);
    
    void setRedValue(char red);
    
    void setGreenValue(char green);
    
    void setBlueValue(char blue);
    
    void setAlphaValue(char alpha);
    
    
};

#endif /* defined(__EngineTest__Pixel__) */
