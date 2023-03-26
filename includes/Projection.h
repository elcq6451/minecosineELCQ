// Created by elcq6451 on 17/03/2023.

#ifndef FOLDER_PROJECTION_H
#define FOLDER_PROJECTION_H
#include<math.h>
#include "./GameEngine.h"

typedef struct Projection Projection;

struct Projection {
    float NEAR;
    float FAR;
    float LEFT;
    float RIGHT;
    float TOP;
    float BOTTOM;
    float projectionMatrix[4][4];
    float toScreenMatrix[4][4];
};

struct Projection *initProjection(struct GameEngine *GE);
#endif //FOLDER_PROJECTION_H
