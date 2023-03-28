// Created by elcq6451 on 03/03/2023.

#ifndef FOLDER_M_MATRIXFUNCTIONS_H
#define FOLDER_M_MATRIXFUNCTIONS_H
#include <math.h>
#include "Miscellaneous.h"
void *translateMatrix(Point3 pos);
void *rotateXMatrix(float angle);
void *rotateYMatrix(float angle);
void *rotateZMatrix(float angle);
void *scaleMatrix(float n);
void *multiplyMatrices(float** first, float** second);
void *multiplyMatrixFloat(float* first[1][4], float* second);

#endif //FOLDER_M_MATRIXFUNCTIONS_H
