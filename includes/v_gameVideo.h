// Created by elcq6451 on 27/02/2023.
#ifndef FOLDER_V_GAMEVIDEO_H
#define FOLDER_V_GAMEVIDEO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/Miscellaneous.h"

typedef struct GameVideo GameVideo;

struct GameVideo {
    Point2 (*initPoint2)(struct GameVideo *, float x, float y);
    Point3 (*initPoint3)(struct GameVideo *, float x, float y, float z);
    void (*plot)(struct GameVideo *, Point2 pos, unsigned short colour);
    void (*PLL)(struct GameVideo *, Point2 self, Point2 self2, unsigned short colour);
    void (*PLH)(struct GameVideo *, Point2 self, Point2 self2, unsigned short colour);
    void (*DrawLine)(struct GameVideo *, Point2 self, Point2 self2, unsigned short colour);
};

Point2 initPoint2(struct GameVideo * inst, float x, float y);
Point3 initPoint3(struct GameVideo * inst, float x, float y, float z);
void Plot(struct GameVideo * inst, Point2 pos, unsigned short colour);
void plotLineLow(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour);
void plotLineHigh(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour);
void DrawLine(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour);
GameVideo initGameVideo();


#endif //FOLDER_V_GAMEVIDEO_H
