// Created by elcq6451 on 17/03/2023.
#include "../includes/Projection.h"


struct Projection *initProjection(struct GameEngine* GE) {
    Projection* p = (Projection *) malloc(sizeof(Projection));
    p->NEAR = GE->camera.nearPlane;
    p->FAR = GE->camera.farPlane;
    p->RIGHT = M_tan(GE->camera.h_fov / 2);
    p->LEFT = -p->RIGHT;
    p->TOP = M_tan(GE->camera.v_fov / 2);
    p->BOTTOM = -p->BOTTOM;
    float array[4][4] = {{2 / (p->RIGHT - p->LEFT), 0, 0, 0},
                         {0, 2 / (p->TOP - p->BOTTOM), 0, 0},
                         {0, 0, (p->FAR + p->NEAR) / (p->FAR - p->NEAR), 1},
                         {0, 0, -2 * p->NEAR * p->FAR /  (p->FAR - p->NEAR), 0}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->projectionMatrix[i][j] = array[i][j];
        }
    }
    float array2[4][4] = {{GE->H_WIDTH, 0, 0, 0},
                         {0, -GE->H_HEIGHT, 0, 0},
                         {0, 0, 1, 0},
                         {GE->H_WIDTH, GE->H_HEIGHT, 0, 1}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->toScreenMatrix[i][j] = array2[i][j];
        }
    }
    return p;
}
