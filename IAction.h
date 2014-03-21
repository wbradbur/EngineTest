//
//  IAction.h
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef EngineTest_IAction_h
#define EngineTest_IAction_h

#include "GameObject.h"

class IAction {
private:
    bool (*function)(Game&, GameObject&);
    
    
public:
    void setAction(bool (*f)(Game&, GameObject&)) {
        function = f;
    }
    
    
	bool doAction(Game& game, GameObject& object) {
        return function(game, object);
    };
};

#endif
