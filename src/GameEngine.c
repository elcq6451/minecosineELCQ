// Created by elcq6451 on 11/03/2023.
#include "fxcg/display.h"
#include "../includes/Camera.h"
#include "../includes/GameEngine.h"
#include "../includes/v_gameVideo.h"

GameEngine initGameEngine() {
    GameEngine GE;
    GameVideo GV;
    Camera camera;
    GE.GV = GV;
    GE.camera = camera;
    Point3 pos = initPoint3(&GV,10, 5 ,1);
    GE.camera = initCamera(&pos);
    GE.WIDTH = LCD_WIDTH_PX;
    GE.DrawLine = DrawLine;
    //GE.initPoint3 = initPoint3;
    //GE.initPoint2 = initPoint2;
    return GE;
};