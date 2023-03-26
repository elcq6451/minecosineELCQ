// Created by elcq6451 on 11/03/2023.
#include "../includes/GameEngine.h"
#include "../includes/Projection.h"


GameEngine initGameEngine() {
    GameEngine GE;
    Camera camera;
    GE.GV = initGameVideo();
    GE.WIDTH = LCD_WIDTH_PX;
    GE.DrawLine = DrawLine;
    GE.create = create;
    GE.initPoint2 = initPoint2;
    GE.initPoint3 = initPoint3;
    return GE;
};
void create (struct GameEngine* GE) {
    Point3 pos = initPoint3(&GE->GV,10, 5 ,1);
    GE->camera = initCamera(&pos);
    GE->projection = initProjection(&GE);
}
