#ifndef FOLDER_VIDEO_H
#define FOLDER_VIDEO_H

#include "./misc.h"

void PlotColourPixel(Point2I location, unsigned short colour);
void PlotLineLow(Point2I self, Point2I self2, unsigned short colour);
void PlotLineHigh(Point2I self, Point2I self2, unsigned short colour);
void DrawLine(Point2I self, Point2I self2, unsigned short colour);
void UpdateScreen();

#endif //FOLDER_VIDEO_H
