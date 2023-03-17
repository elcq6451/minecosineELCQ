// Created by elcq6451 on 11/03/2023.
#include "fxcg/display.h"
#include "../includes/Camera.h"
#include "../includes/GameEngine.h"
#include "../includes/v_gameVideo.h"

GameEngine initGameEngine() {
    GameEngine GE;
    GE.(Camera camera);
    GE.WIDTH = LCD_WIDTH_PX;
    GE.DrawLine = DrawLine;
    GE.initPoint2 = initPoint2;
    return GE;
};

Point2 initPoint2(struct GameEngine * inst, float x, float y) {
    Point2 initialised = {x, y};
    return initialised;
}