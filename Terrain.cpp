//
//  Terrain.cpp
//  CMPS160-Lab3
//
//  Created by Chase Bradbury on 11/11/13.
//  Copyright (c) 2013 Chase Bradbury. All rights reserved.
//


#include "Terrain.h"

/* private members:
int width;
int depth;
float** heights;
Vector3d** normals;
 */

Terrain::Terrain(Image heightmap, float heightScale)
{
    width = heightmap.getWidth();
    depth = heightmap.getHeight();
    heights = (float **) malloc(width * sizeof(float*));
    for (int i = 0; i < width; ++i) {
        heights[i] = (float *) malloc(depth * sizeof(float));
    }
    normals = (Vector3f **) malloc(width * sizeof(Vector3f*));
    for (int i = 0; i < width; ++i) {
        normals[i] = (Vector3f *) malloc(depth * sizeof(Vector3f));
    }
    
    // Generate Geometry
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < depth; ++j) {
            heights[i][j] = (float)(heightmap.getRedValue(i, j)) * heightScale;
        }
    }
}

void Terrain::calculate_normals()
{
    Vector3f v;
    Vector3f w;
    
    Vector3f n;
    
    Vector3f** normals2 = (Vector3f **) malloc(width * sizeof(Vector3f*));
    for (int i = 0; i < width; ++i) {
        normals2[i] = (Vector3f *) malloc(depth * sizeof(Vector3f));
    }
    
    for (int i = 0; i < width - 1; ++i) {
        for (int j = 0; j < depth - 1; ++j) {
            
            v = Vector3f(1, heights[i + 1][j] - heights[i][j], 0);
            
            w = Vector3f(0, heights[i][j + 1] - heights[i][j], 1);
            
            n = v * w;
            
            normals[i][j] = normalize(n);
            
            v = Vector3f(-1, heights[i][j + 1] - heights[i + 1][j + 1], 0);
            
            w = Vector3f(0, heights[i + 1][j] - heights[i + 1][j + 1], -1);
            
            n = v * w;
            
            normals2[i][j] = normalize(n);
            
            
            
        }
    }
    
    for (int i = 0; i < width - 1; ++i) {
        for (int j = 0; j < depth - 1; ++j) {
            Vector3f a = normals2[i][j];
            Vector3f b = normals[i + 1][j];
            Vector3f c = normals2[i + 1][j];
            Vector3f d = normals[i][j + 1];
            Vector3f e = normals2[i][j + 1];
            Vector3f f = normals[i + 1][j + 1];
            
            normals[i + 1][j + 1].x = (a.x + b.x + c.x + d.x + e.x + f.x) / 6;
            normals[i + 1][j + 1].y = (a.y + b.y + c.y + d.y + e.y + f.y) / 6;
            normals[i + 1][j + 1].z = (a.z + b.z + c.z + d.z + e.z + f.z) / 6;
        }
    }
    
}
//
void Terrain::draw_terrain()
{
    for (int i = 0; i < width - 1; ++i) {
        glBegin(GL_TRIANGLE_STRIP);
        
        for (int j = 0; j < depth - 1; ++j) {
            glTexCoord2f((float)i / width, (float)j / depth);
            glNormal3f(normals[i][j].x, normals[i][j].y, normals[i][j].z);
            glVertex3f(i, heights[i][j], j);
            
            glTexCoord2f((float)(i + 1) / width, (float)j / depth);
            glVertex3f(i + 1, heights[i+1][j], j);
        }
        glEnd();
    }
}