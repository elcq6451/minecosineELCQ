#include "../includes/Video.h"
#include <fxcg/display.h>

void PlotColourPixel(Point2I location, unsigned short colour) {  //plots a Colour at a specific pixel
    unsigned short *vramPointer = GetVRAMAddress();
    vramPointer += location.y*384 + location.x;
    *vramPointer = colour;
}

/*
 * Draws a line that is larger than 45 deg and less than or equal to 90 deg
 * 45 < x <= 90
 * */
void PlotLineLow(Point2I self, Point2I self2, unsigned short colour) {
    int dy = self2.y - self.y;
    int dx = self2.x - self.x;
    int yi = 1;
    if(dy < 0 ){
        yi = -1;
        dy = -dy;
    }
    int D = (2 * dy) - dx;
    int y = self.y;
    for (int x = self.x; x <= self2.x; x++) {
        Point2I pos;
        pos.x = x; pos.y = y;
        PlotColourPixel(pos, colour);
        if(D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }else{
            D = D + 2*dy;
        }
    }
};

/*
 * Draws a line that is between 0deg and 45deg
 * */
void PlotLineHigh(Point2I self, Point2I self2, unsigned short colour) {
    int dy = self2.y - self.y;
    int dx = self2.x - self.x;
    int xi = 1;
    if(dx < 0 ){
        xi = -1;
        dx = -dx;
    }
    int D = (2 * dx) - dy;
    int x = self.x;
    for (int y = self.y; y <= self2.y; y++) {
        Point2I pos;
        pos.x = x; pos.y = y;
        PlotColourPixel(pos, colour);
        if(D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }else{
            D = D + 2*dx;
        }
    }
}

/*
 * Chooses to use either draw a line High or Low
 */
void DrawLine(Point2I self, Point2I self2, unsigned short colour) {
    if(abs(self2.y - self.y) < abs(self2.x - self.x)) {
        if(self.x > self2.x) {
            PlotLineLow(self2, self, colour);
        }
        else{
            PlotLineLow(self, self2, colour);
        }
    }
    else{
        if(self.y > self2.y) {
            PlotLineHigh(self2, self, colour);
        }
        else{
            PlotLineHigh(self, self2, colour);
        }
    }
}
