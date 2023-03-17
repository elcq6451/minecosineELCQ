// Created by elcq6451 on 27/02/2023.
#ifndef FOLDER_V_GAMEVIDEO_H
#define FOLDER_V_GAMEVIDEO_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../includes/Miscellaneous.h"


Point3 initPoint3(float x, float y, float z);
void Plot(Point2 pos, unsigned short colour);
void plotLineLow(Point2 self, Point2 self2, unsigned short colour);
void plotLineHigh(Point2 self, Point2 self2, unsigned short colour);
void DrawLine(Point2 self, Point2 self2, unsigned short colour);

#endif //FOLDER_V_GAMEVIDEO_H
