#ifndef FOLDER_MATH_H
#define FOLDER_MATH_H

#include <stdio.h>
#include <stdlib.h>

float** matrix_multiply(float** A, float** B, int rowsA, int colsA, int rowsB, int colsB);
float** multiplyMatrixByScalar(float** A, float scalar, int rows, int cols);
int factorial(int x);
float M_pow(float base, float power);
float M_sin(float);
float M_cos(float);
float M_tan(float);

#endif //FOLDER_MATH_H
