//
// Created by elcq6451 on 27/02/2023.
//
#include <stdio.h>
#include <fxcg/display.h>
#include "../includes/v_gameVideo.h"


Point3 initialisePoint3(float x, float y, float z) {
    Point3 initialised = { x, y, z};
    return initialised;
}

void printPoint(Point3 *self) {
    char String[] = "";
    String =  {"%f, %f, %f\n", self->x, self->y, self->z};
    PrintXY(30,30, String, TEXT_MODE_NORMAL, TEXT_COLOR_BLUE);
}