#include "../includes/GameEngine.h"
#include "../includes/Video.h"

GameEngine InitGameEngine(int height, int width) {
    GameEngine gameEngine = {0};
    gameEngine.width = width;
    gameEngine.height = height;
    gameEngine.initPoint2I = &initPoint2I;
    gameEngine.initPoint2F = &initPoint2F;
    gameEngine.initPoint3F = &initPoint3F;
    gameEngine.PlotColourPixel = &PlotColourPixel;
    gameEngine.DrawLine = &DrawLine;
    gameEngine.UpdateScreen = &UpdateScreen;

    return gameEngine;
}