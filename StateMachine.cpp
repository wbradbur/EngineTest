//
//  StateMachine.cpp
//  EngineTest
//
//  Created by Chase Bradbury on 11/24/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#include "StateMachine.h"

bool state_null_action(Game& game, GameObject& object) {
    return true;
}

stateref make_state(IAction action, IAction entryAction, IAction exitAction, int numTransitions) {
    stateref state = (stateref)malloc(sizeof(state_t));
    state->action = action;
    state->entryAction = entryAction;
    state->exitAction = exitAction;
    state->transitions = (transitionref*)malloc(numTransitions * sizeof(transitionref));
    for (int i = 0; i < numTransitions; ++i) {
        state->transitions[i] = (transitionref)malloc(sizeof(transition_t));
        state->transitions[i] = NULL;
    }
    state->numTransitions = numTransitions;
    //state.transitions = NULL;
    return state;
}

transitionref make_transition(stateref fromState, IAction action, ICondition condition, stateref toState) {
    transitionref transition = (transitionref)malloc(sizeof(transition_t));
    transition->action = action;
    transition->condition = condition;
    transition->target = toState;
    for (int i = 0; i < fromState->numTransitions; ++i) {
        if (fromState->transitions[i] == NULL) {
            fromState->transitions[i] = transition;
            break;
        }
    }
    
    /*
    (fromState->transitions[i] != NULL) {
        ++i;
    }
    fromState->transitions[i] = transition;
    //fromState.transition = &transition;*/
    return transition;
}

IAction* StateMachine::update(Game& game, GameObject& object)
{
    transitionref triggeredTransition = NULL;
    IAction* actions = (IAction*)malloc(4 * sizeof(IAction));
    
    for (int i = 0; i < currentState->numTransitions; ++i)
    {
        if (currentState->transitions[i]->condition.test(game, object))
        {
            triggeredTransition = currentState->transitions[i];
            break;
        }
    }
    
    /*if (currentState.transition->condition.test(game, object))
    {
        triggeredTransition = currentState.transition;
    }
     */
    int actionCount = 0;
    if (triggeredTransition != NULL)
    {
        stateref targetState = triggeredTransition->target;
        IAction currAction = currentState->exitAction;
        actions[actionCount++] = currAction;
        
        currAction = triggeredTransition->action;
        actions[actionCount++] = currAction;
        
        currentState = targetState;
        currAction = currentState->entryAction;
        actions[actionCount++] = currAction;
        
        currAction = currentState->action;
        actions[actionCount++] = currAction;
        
        
        return actions;
    }
    actions[actionCount++] = currentState->action;
    
    IAction nullAction;
    nullAction.setAction(state_null_action);
    actions[actionCount++] = nullAction;
    actions[actionCount++] = nullAction;
    actions[actionCount++] = nullAction;
    return actions;
    //return &currentState.action;
}