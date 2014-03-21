//
//  GameObject.h
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__GameObject__
#define __EngineTest__GameObject__

#include <iostream>

#include "Game.h"
//#include "GameObject.h"

#define XROTATE 0
#define YROTATE 1
#define ZROTATE 2


class GameObject {
private:
    float x;
    float y;
    float z;
    float xRot;
    float yRot;
    float zRot;
    void* special;
    bool (*function)(Game&, GameObject&);
    
public:
    void setUpdateFunc(bool (*f)(Game&, GameObject&)) {
        function = f;
    }
    
	bool update(Game& game, GameObject& object) {
        return function(game, object);
    };
    
    GameObject(float nx, float ny, float nz) { x = nx; y = ny; z = nz; }
    
    float getx() { return x; }
    
    float gety() { return y; }
    
    float getz() { return z; }
    
    void move(float nx, float ny, float nz) { x += nx; y += ny; z += nz; }
    
    void moveTo(float nx, float ny, float nz) { x = nx; y = ny; z = nz; }
    
    void rotate(int axis, float degrees);
    
    void rotate(float x, float y, float z);
    
    void draw();
};


#endif /* defined(__EngineTest__GameObject__) */
