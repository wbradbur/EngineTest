//
//  GameObject2d.h
//  EngineTest
//
//  Created by Chase Bradbury on 3/20/14.
//  Copyright (c) 2014 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__GameObject2d__
#define __EngineTest__GameObject2d__

#include <iostream>

class GameObject2d {
private:
    float x;
    float y;
    float rotation;
    void* special;
    bool (*function)();
    
public:
    void setUpdateFunc(bool (*f)()) {
        function = f;
    }
    
	bool update() {
        return function();
    };
    
    GameObject2d(float nx, float ny) { x = nx; y = ny; }
    
    float getx() { return x; }
    
    float gety() { return y; }
    
    void move(float nx, float ny) { x += nx; y += ny; }
    
    void moveTo(float nx, float ny) { x = nx; y = ny; }
    
    void rotate(float degrees);
    
    void rotateRadians(float radians);
    
    void setRotation(float degrees);
    
    void setRotationRadians(float degrees);
    
    void draw();
};

#endif /* defined(__EngineTest__GameObject2d__) */
