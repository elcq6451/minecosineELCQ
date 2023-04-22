#include "../includes/GameEngine.h"


GameEngine InitGameEngine(int height, int width) {
    GameEngine gameEngine = {0};
    gameEngine.initPoint2I = &initPoint2I;
    gameEngine.initPoint2F = &initPoint2F;
    gameEngine.initPoint3F = &initPoint3F;
    gameEngine.PlotColourPixel = &PlotColourPixel;
    gameEngine.DrawLine = &DrawLine;
    Point3F position = initPoint3F(0,0,0);
    gameEngine.Camera = initializeCamera(&gameEngine.Camera, &position);
    gameEngine.Projection = initProjection(&gameEngine.Camera);

    return gameEngine;
}