// Created by elcq6451 on 27/02/2023.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fxcg/display.h>
#include "../includes/v_gameVideo.h"
#include "../includes/Miscellaneous.h"



GameVideo initGameVideo(){
    GameVideo GV;
    GV.initPoint3 = &initPoint3;
    GV.plot = &Plot;
    GV.PLL = &plotLineLow;
    GV.PLH = &plotLineHigh;
    GV.DrawLine = &DrawLine;
    return GV;
}

Point2 initPoint2(struct GameVideo * inst, int x, int y) {
    Point2 initialised = {x, y};
    return initialised;
}
Point3 initPoint3(struct GameVideo * inst, float x, float y, float z) {
    Point3 initialised = {x, y, z};
    return initialised;
}

void Plot(struct GameVideo * inst, Point2 pos, unsigned short colour) {
    unsigned short *v = GetVRAMAddress();
    v += pos.y*384 + pos.x;
    *v = colour;
}

void plotLineLow(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour) {
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
        Point2 pos;
        pos.x = x; pos.y = y;
        Plot(inst, pos, colour);
        if(D > 0) {
            y = y + yi;
            D = D + (2 * (dy - dx));
        }else{
            D = D + 2*dy;
        }
    }
};

void plotLineHigh(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour) {
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
        Point2 pos;
        pos.x = x; pos.y = y;
        Plot(inst, pos, colour);
        if(D > 0) {
            x = x + xi;
            D = D + (2 * (dx - dy));
        }else{
            D = D + 2*dx;
        }
    }
};

void DrawLine(struct GameVideo * inst, Point2 self, Point2 self2, unsigned short colour) {
    if(abs(self2.y - self.y) < abs(self2.x - self.x)) {
        if(self.x > self2.x) {
            plotLineLow(inst, self2, self, colour);
        }
        else{
            plotLineLow(inst, self, self2, colour);
        }
    }
    else{
        if(self.y > self2.y) {
            plotLineHigh(inst, self2, self, colour);
        }
        else{
            plotLineHigh(inst, self, self2, colour);
        }
    }
    Bdisp_PutDisp_DD();
}
void createObject(void) {

}