//
//  Vector3f.cpp
//  CMPS160-Lab3
//
//  Created by Chase Bradbury on 11/11/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#include "Vector3f.h"

/*** Constructors ***/

Vector3f::Vector3f() {
    this->x = 0;
    this->y = 0;
    this->z = 0;
}

Vector3f::Vector3f(float x, float y, float z) {
    this->x = x;
    this->y = y;
    this->z = z;
}



/*** Class functions ***/

void Vector3f::normalize() {
    float tempx = x / sqrt(x * x + y * y + z * z);
    float tempy = y / sqrt(x * x + y * y + z * z);
    float tempz = z / sqrt(x * x + y * y + z * z);
    x = tempx;
    y = tempy;
    z = tempz;
}

bool Vector3f::isNormal() {
    return (this->length() == 1);
}

float Vector3f::length() {
    return sqrt(x * x + y * y + z * z);
}



/*** Operator overloads ***/

// Vector addition
Vector3f Vector3f::operator +(Vector3f other) {
    Vector3f newVector;
    newVector.x = x + other.x;
    newVector.y = y + other.y;
    newVector.z = z + other.z;
    return newVector;
}
// Vector subtraction
Vector3f Vector3f::operator -(Vector3f other) {
    Vector3f newVector;
    newVector.x = x - other.x;
    newVector.y = y - other.y;
    newVector.z = z - other.z;
    return newVector;
}
// Scalar float multiplication
Vector3f Vector3f::operator *(float scale) {
    Vector3f newVector;
    newVector.x = x * scale;
    newVector.y = y * scale;
    newVector.z = z * scale;
    return newVector;
}
// Cross multiplication
Vector3f Vector3f::operator *(Vector3f other) {
    Vector3f newVector;
    newVector.x = y * other.z - z * other.y;
    newVector.y = z * other.x - x * other.z;
    newVector.z = x * other.y - y * other.x;
    return newVector;
}
// Integer incrementation
Vector3f Vector3f::operator ++() {
    Vector3f newVector;
    newVector.x = ++x;
    newVector.y = ++y;
    newVector.z = ++z;
    return newVector;
}
// Integer decrementation
Vector3f Vector3f::operator --() {
    Vector3f newVector;
    newVector.x = --x;
    newVector.y = --y;
    newVector.z = --z;
    return newVector;
}
// Vector addition
Vector3f Vector3f::operator +=(Vector3f other) {
    x = x + other.x;
    y = y + other.y;
    z = z + other.z;
    return *this;
}
// Vector subtraction
Vector3f Vector3f::operator -=(Vector3f other) {
    x = x - other.x;
    y = y - other.y;
    z = z - other.z;
    return *this;
}
// Scalar float multiplication
Vector3f Vector3f::operator *=(float scale) {
    x = x * scale;
    y = y * scale;
    z = z * scale;
    return *this;
}
// Cross multiplication
Vector3f Vector3f::operator *=(Vector3f other) {
    x = y * other.z - z * other.y;
    y = z * other.x - x * other.z;
    z = x * other.y - y * other.x;
    return *this;
}



/*** Utility functions ***/

ostream& operator <<(ostream& stream, const Vector3f& vector) {
    stream << "[" << vector.x << ", " << vector.y << ", " << vector.z << "]";
    return stream;
}

Vector3f normalize(Vector3f vector) {
    Vector3f newVector;
    newVector.x = vector.x / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    newVector.y = vector.y / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    newVector.z = vector.z / sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
    return newVector;
}