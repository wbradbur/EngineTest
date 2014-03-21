//
//  main.cpp
//  EngineTest
//
//  Created by Chase Bradbury on 11/12/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>

#include "Vector3f.h"
#include "ICondition.h"
#include "IAction.h"
//#include "GameObject.h"
#include "StateMachine.h"
#include "LinkedList.h"
#include "Image.h"
#include "Terrain.h"

using namespace std;

#define PI 3.14159265

float xrot, yrot = 0;
bool keyState[256] = { false };
int windowWidth, windowHeight;

GLuint texture;

Terrain myTerrain;

float lightAngle = 0;
float near = .01;
float far = 1;

bool surface = true;

Vector3f camP;
Vector3f camR;

int mouseXPrev;
int mouseYPrev;


float lightPosition[4];
float diffuseColour[3];
float ambientColour[4];


void cb_display() {
    static clock_t previous_clock = 0;
    static clock_t ms_since_last = 0;
    clock_t now = clock() / (CLOCKS_PER_SEC / 1000);
    ms_since_last = now - previous_clock;
    if (ms_since_last < 20) {
        return;
    }
    previous_clock = now;
    
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
    
    glTranslatef(camP.x, camP.y, camP.z);
    glRotatef(camR.x, 1, 0, 0);
    glRotatef(camR.y, 0, 1, 0);
    glRotatef(camR.z, 0, 0, 1);
    
    //gluLookAt(camP.x, camP.y, camP.z, 0,0,0,0,1,0);
    
    glPushMatrix();
    glRotatef(lightAngle, 0, 1, 0);
    
	glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
    
    glPopMatrix();
    
    glLightfv(GL_LIGHT1, GL_AMBIENT, ambientColour);
    
	myTerrain.draw_terrain();
    
    glDepthRange(near, far);
    
	glFlush();
	glutSwapBuffers(); // for smoother animation
}

void loadTextureMap(canvas_t tex) {
	glEnable(GL_TEXTURE_2D);
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, tex.height, tex.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.pixels);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
	glTexParameterf( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
}

void cb_idle() {
	//drawTexture();
	glutPostRedisplay();
}

void cb_reshape(int w, int h) {
	windowWidth = w;
	windowHeight = h;
	int aspect = w/h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0, aspect, 0.01, 10000); // necessary to preserve aspect ratio
	glMatrixMode(GL_MODELVIEW);
}

void cb_mouseclick(int button, int state, int x, int y) {
    mouseXPrev = x;
    mouseYPrev = y;
}

void cb_mousemove(int x, int y) {
    camR.y += x - mouseXPrev;
    camR.x += y - mouseYPrev;
    mouseXPrev = x;
    mouseYPrev = y;
}

void cb_keyboard(unsigned char key, int x, int y) {
    switch(key) {
		case 'w':
			camP.z += 5;
			break;
        case 's':
			camP.z -= 5;
			break;
        case 'q':
			exit(0);
			break;
        case 'e':
			lightAngle += 5;
            if (lightAngle > 360) {
                lightAngle = 0;
            }
			break;
    }
}



bool state3bool = false;

bool condition_test(Game& game, GameObject& object){ return game.time == 0;}

bool action_test(Game& game, GameObject& object){
    if (game.time == object.getx()) {
        game.setTime(1);
        return false;
    }
    game.setTime(0);
    return true;
}

bool null_action(Game& game, GameObject& object) {
    return true;
}

bool state1_action(Game& game, GameObject& object) {
    cout << "State 1: " << object.getx() << "\t Time: " << game.time << endl;
    object.move(5, 5, 5);
    ++game.time;
    return true;
}

bool state2_action(Game& game, GameObject& object) {
    cout << "State 2: " << object.getx() << "\t Time: " << game.time << endl;
    object.move(-5, -5, -5);
    ++game.time;
    return true;
}

bool state3_action(Game& game, GameObject& object) {
    cout << "State 3: " << object.getx() << "\t Time: " << game.time << endl;
    if (state3bool)
        object.move(-10, -10, -10);
    else
        object.move(10, 10, 10);
    ++game.time;
    return true;
}

bool state1_condition(Game& game, GameObject& object) {
    return object.getx() >= 20;
}

bool state2_condition(Game& game, GameObject& object) {
    return object.getx() <= 0;
}

bool state2_condition2(Game& game, GameObject& object) {
    return game.time % 5;
}

bool state3_enter(Game& game, GameObject& object) {
    state3bool = !state3bool;
    return true;
}

int main(int argc, char * argv[])
{

    // test vector class
    Vector3f v1(1, .5, 0);
    Vector3f v2(1, 3, 1);
    cout << v1 << " " << v2 << endl;
    Vector3f v3 = v1 + v2;
    cout << v3 << endl;
    v3 = v1 - v2;
    cout << v3 << endl;
    v3 = v1 * 3;
    cout << v3 << endl;
    v3 = v1 * v2;
    cout << v3 << endl;
    v2 = normalize(v3);
    cout << v2 << endl;
    v3.normalize();
    cout << v3 << endl;
    cout << v3.x + v3.y + v3.z << endl;
    ++v1;
    cout << v1 << endl;
    --v1;
    cout << v1 << endl;
    if (v3.isNormal()) {
        cout << "yay" << endl;
    } else {
        cout << sqrt(v3.x * v3.x + v3.y * v3.y + v3.z * v3.z) << endl;
    }
    
    
    
    // test fsm
    Game sup = Game();
    
    GameObject obj = GameObject(0, 0, 0);
    
    IAction action;
    action.setAction(action_test);
    
    action.doAction(sup, obj);
    
    ICondition tester;
    tester.setTest(condition_test);
    
    if (tester.test(sup, obj)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    
    if (action.doAction(sup, obj)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    
    if (tester.test(sup, obj)) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }
    IAction nullAction;
    nullAction.setAction(null_action);
    
    IAction state1Action;
    state1Action.setAction(state1_action);
    
    IAction state2Action;
    state2Action.setAction(state2_action);
    
    IAction state3Action;
    state3Action.setAction(state3_action);
    
    IAction state3Enter;
    state3Enter.setAction(state3_enter);
    
    ICondition state1Condition;
    state1Condition.setTest(state1_condition);
    
    ICondition state2Condition;
    state2Condition.setTest(state2_condition);
    
    ICondition state2Condition2;
    state2Condition2.setTest(state2_condition2);
    
    stateref state1 = make_state(state1Action, nullAction, nullAction, 1);
    stateref state2 = make_state(state2Action, nullAction, nullAction, 2);
    stateref state3 = make_state(state3Action, state3Enter, nullAction, 2);
    
    make_transition(state1, nullAction, state1Condition, state2);
    make_transition(state2, nullAction, state2Condition, state1);
    make_transition(state2, nullAction, state2Condition2, state3);
    make_transition(state3, nullAction, state1Condition, state1);
    make_transition(state3, nullAction, state2Condition, state2);
    
    StateMachine FSM = StateMachine(state1);
    
    IAction* actions = FSM.update(sup, obj);
    actions[0].doAction(sup, obj);
    
    for (int i = 0; i < 300; ++i) {
        actions = FSM.update(sup, obj);
        for (int i = 0; i < 4; ++i) {
            actions[i].doAction(sup, obj);
        }
    }
    
    
    
    // test linked list class
    
    LinkedList list = LinkedList();
    
    Vector3f vect(.05, 7.1, -2.3);
    for (int i = 0; i < 10; ++i) {
        vect = vect * i;
        list.insertBeforeFirst(i, &vect);
    }
    
    //list.deleteKey(5);
    list.deleteFirst();
    list.insertBeforeFirst(4, &vect);
    //list.insertSorted(3, &vect);
    
    //list.printList();
    
    Image testImage = Image((char*)"/Users/chasebradbury/Documents/EngineTest/EngineTest/assets/testheightmaprgb.ppm");
    cout << testImage.getWidth() << endl;
    cout << testImage.getBlueValue(testImage.getWidth()/2, testImage.getHeight()/2) << endl;
    for (int i = 0; i < testImage.getWidth(); ++i) {
        for (int j = 0; j < testImage.getHeight(); ++j) {
            testImage.setBlueValue(i, j, 255);
        }
    }
    testImage.savePPM((char*)"/Users/chasebradbury/Documents/EngineTest/EngineTest/assets/testmodified.ppm");
    
    Image testImage2 = Image((char*)"/Users/chasebradbury/Documents/EngineTest/EngineTest/assets/colortest.ppm");
    cout << testImage2.getWidth() << endl;
    cout << testImage2.getBlueValue(testImage2.getWidth()/2, testImage2.getHeight()/2) << endl;
    testImage2.setAlphaValue(testImage2.getWidth()/2, testImage2.getHeight()/2, 255);
    testImage2.savePPM((char*)"/Users/chasebradbury/Documents/EngineTest/EngineTest/assets/testcolormod.ppm");
    
    
    
    
    
    /********* Terrain Test *******/
    
    
    glutInit(&argc, argv);
    
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(750, 750);
	glutCreateWindow("Lab 3: Terrain Mapping");
	glutIgnoreKeyRepeat(false);
    
	glEnable(GL_TEXTURE_2D);
    
	myTerrain = Terrain(testImage, .2);
    
    //myTerrain.generate_geometry(terrain, 1, texture);
    myTerrain.calculate_normals();
    
    camP.x = 0;
    camP.y = 0;
    camP.z = 0;
    
    camR.x = 0;
    camR.y = 0;
    camR.z = 0;
    
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	glEnable (GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	
	lightPosition[0] = 2000;
	lightPosition[1] = 2000;
	lightPosition[2] = 2000;
	lightPosition[3] = 10;
    
    ambientColour[0] = .4;
	ambientColour[1] = .1;
	ambientColour[2] = .1;
	ambientColour[3] = 500;
    
    
	
	glutDisplayFunc(cb_display);
	glutReshapeFunc(cb_reshape);
	glutIdleFunc(cb_idle);
    glutKeyboardFunc(cb_keyboard);
    glutMotionFunc(cb_mousemove);
    glutMouseFunc(cb_mouseclick);
    
	glClearColor(0,0,0,0); // set background to black
    
	glutMainLoop();
    
    return 0;
}

