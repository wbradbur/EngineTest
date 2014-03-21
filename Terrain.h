//
//  Terrain.h
//  CMPS160-Lab3
//
//  Created by Chase Bradbury on 11/11/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//

#ifndef __CMPS160_Lab3__Terrain__
#define __CMPS160_Lab3__Terrain__

#include <stdlib.h>
#include <stdio.h>
#include <GLUT/glut.h>
#include <iostream>

#include "Vector3f.h"
#include "ppm_canvas.h"
#include "Image.h"

class Terrain {
private:
    int width;
    int depth;
    float** heights;
    Vector3f** normals;
    
public:
    
    // Constructor for terrain
    Terrain(){};
    
    Terrain(Image heightmap, float heightScale);
    
    void generate_geometry(float heightScale);
    
    void calculate_normals();
    //
    void draw_terrain();
};

#endif /* defined(__CMPS160_Lab3__Terrain__) */
