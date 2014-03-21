//
//  Game.h
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__Game__
#define __EngineTest__Game__

#include <iostream>

//#include "StateMachine.h"
//#include "GameObject.h"

class Game {
public:
    time_t time;
    
    //GameObject globalObject;
    
    //StateMachine gameState;
//public:
    
    Game() {
        time = 0;
    };
    
    void initGameState();
    
    void setTime(time_t newTime) { time = newTime; }
    
    void update();
    
    void draw();
    
    void getState();
    
    time_t getTime() { return time; }
};

#endif /* defined(__EngineTest__Game__) */
