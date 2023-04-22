#ifndef FOLDER_GAMEENGINE_H
#define FOLDER_GAMEENGINE_H

#include "./misc.h"
#include "./Video.h"
#include "./Camera.h"
#include "./Projection.h"

typedef struct GameEngine {
    int height;
    int width;
    Camera Camera;
    Projection* Projection;
    Point2I (*initPoint2I) (int, int);
    Point2F (*initPoint2F) (float, float);
    Point3F (*initPoint3F) (float, float, float);
    void (*PlotColourPixel) (Point2I, unsigned short);
    void (*DrawLine) (Point2I, Point2I, unsigned short);
}GameEngine;

GameEngine InitGameEngine(int height, int width);

#endif //FOLDER_GAMEENGINE_H
