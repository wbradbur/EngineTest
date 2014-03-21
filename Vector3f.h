//
//  Vector3f.h
//  CMPS160-Lab3
//
//  Created by Chase Bradbury on 11/11/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __CMPS160_Lab3___dVector__
#define __CMPS160_Lab3___dVector__

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include <math.h>
#include <iostream>
using namespace std;

/*** Vector class ***/

class Vector3f {
public:
    float x;
    float y;
    float z;
    
    Vector3f();
    Vector3f(float x, float y, float z);
    
    void normalize();
    bool isNormal();
    float length();
    
    Vector3f operator +(Vector3f);
    Vector3f operator -(Vector3f);
    Vector3f operator *(float);
    Vector3f operator *(Vector3f);
    Vector3f operator ++();
    Vector3f operator --();
    Vector3f operator +=(Vector3f);
    Vector3f operator -=(Vector3f);
    Vector3f operator *=(float);
    Vector3f operator *=(Vector3f);
    friend ostream& operator <<(ostream& stream, const Vector3f& vector);
};

ostream& operator <<(ostream& stream, const Vector3f& vector);

Vector3f normalize(Vector3f);

#endif /* defined(__CMPS160_Lab3___dVector__) */
