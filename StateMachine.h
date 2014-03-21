//
//  StateMachine.h
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __EngineTest__StateMachine__
#define __EngineTest__StateMachine__

#include <iostream>

#include "Game.h"
#include "IAction.h"
#include "ICondition.h"

struct transition_t;

typedef transition_t* transitionref;

typedef struct state_t {
    IAction action;
    IAction entryAction;
    IAction exitAction;
    int numTransitions;
    transitionref* transitions;
} state_t;

typedef state_t* stateref;

typedef struct transition_t {
    stateref target;
    IAction action;
    ICondition condition;
} transition_t;

stateref make_state(IAction action, IAction entryAction, IAction exitAction, int numTransitions);

transitionref make_transition(stateref fromState, IAction action, ICondition condition, stateref toState);

class StateMachine {
public:
    
    stateref currentState;
    
    StateMachine(stateref initState) { currentState = initState; };
    
    IAction* update(Game& game, GameObject& object);
};

#endif /* defined(__EngineTest__StateMachine__) */
