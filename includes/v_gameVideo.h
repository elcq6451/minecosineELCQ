// Created by elcq6451 on 27/02/2023.
#ifndef FOLDER_V_GAMEVIDEO_H
#define FOLDER_V_GAMEVIDEO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Point3 {
    float x;
    float y;
    float z;
} Point3;

typedef struct Point2 {
    int x;
    int y;
} Point2;


Point3 initialisePoint3(float x, float y, float z);
void Plot(int X, int Y);
void plotLineLow(Point2 self, Point2 self2);
void plotLineHigh(Point2 self, Point2 self2);
void DrawLine(Point2 self, Point2 self2);


#endif //FOLDER_V_GAMEVIDEO_H
