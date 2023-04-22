#ifndef FOLDER_PROJECTION_H
#define FOLDER_PROJECTION_H

#include "../includes/Camera.h"
#include <fxcg/display.h>
#include <stdlib.h>

typedef struct Projection {
    float NEAR;
    float FAR;
    float LEFT;
    float RIGHT;
    float TOP;
    float BOTTOM;
    float projectionMatrix[4][4];
    float toScreenMatrix[4][4];

}Projection;

Projection *initProjection(struct Camera* Camera);
#endif //FOLDER_PROJECTION_H
