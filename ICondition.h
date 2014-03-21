//
//  ICondition.h
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef EngineTest_ICondition_h
#define EngineTest_ICondition_h

#include "GameObject.h"

#include "Game.h"

class ICondition {
private:
    bool (*function)(Game&, GameObject&);
    
    
public:
    void setTest(bool (*f)(Game&, GameObject&)) {
        function = f;
    }
    
    
	bool test(Game& game, GameObject& object) {
        return function(game, object);
    };
	
};

#endif
