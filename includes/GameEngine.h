// Created by elcq6451 on 11/03/2023.

#ifndef FOLDER_GAMEENGINE_H
#define FOLDER_GAMEENGINE_H
#include "../includes/Camera.h"
//#include "../includes/Projection.h"
#include "../includes/Miscellaneous.h"

typedef struct GameEngine GameEngine;

struct GameEngine {
    GameVideo GV;
    int HEIGHT;
    int WIDTH;
    float H_HEIGHT;
    float H_WIDTH;
    float FPS;
    double CLOCK; //add it later
    void (*DrawLine)(struct GameVideo *, Point2, Point2, unsigned short);
    Point2 (*initPoint2)(struct GameVideo*, int, int);
    Point3 (*initPoint3)(struct GameVideo*, float, float, float);

    Camera camera;
    //Projection projection;
    //Object
};

GameEngine initGameEngine();
#endif //FOLDER_GAMEENGINE_H
