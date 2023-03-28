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
void *multiplyMatrices(float** first, int r1, int c1, float** second, int c2);
float *multiplyMatrixByScalar(float* matrix, int rows, int cols, float scalar);

#endif //FOLDER_M_MATRIXFUNCTIONS_H
