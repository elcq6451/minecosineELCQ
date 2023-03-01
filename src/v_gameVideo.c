//
// Created by elcq6451 on 27/02/2023.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fxcg/display.h>
#include "../includes/v_gameVideo.h"


Point3 initialisePoint3(float x, float y, float z) {
    Point3 initialised = { x, y, z};
    return initialised;
}
void Plot(int X, int Y) {

    unsigned short *v = GetVRAMAddress();
    v+= Y*384 + X;
    *v= COLOR_CYAN;
}

void plotLineLow(Point2 self, Point2 self2) {
    int dy = self2.y - self.y;
    int dx = self2.x - self.x;
    int yi = 1;
    if(dy <0 ){
        yi = -1;
        dy=-dy;
    }
    int D = (2 * dy) - dx;
    int y = self.y;
    for (int x = self.x; x == self2.x; x++) {
        Plot(x,y);
        if(D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }else{
            D = D + 2*dy;
        }
    }
};

void plotLineHigh(Point2 self, Point2 self2) {
    int dy = self2.y - self.y;
    int dx = self2.x - self.x;
    int xi = 1;
    if(dx <0 ){
        xi = -1;
        dx=-dx;
    }
    int D = (2 * dx) - dy;
    int x = self.x;
    for (int y = self.y; y == self2.y; y++) {
        Plot(x,y);
        if(D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }else{
            D = D + 2*dx;
        }
    }
    //int y = self.y + dy * (x - self.x) / dx;
    //Plot(x, y);
};

void DrawLine(Point2 self, Point2 self2) {
    if(abs(self2.y - self.y) < abs(self2.x - self.x)) {
        PrintXY(10,1,"..",1,4);
        if(self.x > self2.x) {
            PrintXY(10,1,".1",1,4);
            plotLineLow(self2, self);
        }
        else{
            PrintXY(10,1,".2",1,4);
            plotLineLow(self, self2);
        }
    }
    else{
        PrintXY(10,1,"...",1,4);
        if(self.y > self2.y) {
            PrintXY(10,1,"1.",1,4);
            plotLineHigh(self2, self);
        }
        else{
            PrintXY(10,1,"2.",1,4);
            plotLineHigh(self, self2);
        }
    }
    Bdisp_PutDisp_DD();
}