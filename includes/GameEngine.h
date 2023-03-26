// Created by elcq6451 on 11/03/2023.

#ifndef FOLDER_GAMEENGINE_H
#define FOLDER_GAMEENGINE_H
#include "fxcg/display.h"
#include "../includes/Camera.h"
#include "./Miscellaneous.h"
#include "./v_gameVideo.h"

struct Projection;
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
    void (*create)(struct GameEngine*);
    Point2 (*initPoint2)(struct GameVideo *, float, float);
    Point3 (*initPoint3)(struct GameVideo *, float, float, float);

    Camera camera;
    struct Projection *projection;
    //Object
};

GameEngine initGameEngine();
void create (struct GameEngine*);
#endif //FOLDER_GAMEENGINE_H
