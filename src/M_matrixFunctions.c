// Created by elcq6451 on 03/03/2023.
#include "../includes/M_matrixFunctions.h"
#include <stdlib.h>


void *translateMatrix(Point3 pos) {
    int matrix[4][4] = {{1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {pos.x, pos.y, pos.z, 1}};
    void* pointer = malloc(sizeof(matrix));
    return pointer;
}

void *rotateXMatrix(float angle) {
    float matrix[4][4] = {{1, 0, 0, 0},
                          {0, cos(angle), sin(angle), 0},
                          {0, -sin(angle), cos(angle), 0},
                          {0, 0, 0, 1}};
    void* pointer = malloc(sizeof(matrix));
    return pointer;
}
void *rotateYMatrix(float angle) {
    float matrix[4][4] = {{cos(angle), 0, -sin(angle), 0},
                          {0, 1, 0, 0},
                          {sin(angle), 0, cos(angle), 0},
                          {0, 0, 0, 1}};
    void* pointer = malloc(sizeof(matrix));
    return pointer;
}
void *rotateZMatrix(float angle) {
    float matrix[4][4] = {{cos(angle), sin(angle), 0, 0},
                          {-sin(angle), cos(angle), 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    void* pointer = malloc(sizeof(matrix));
    return pointer;
}
void *scaleMatrix(float n) {
    float matrix[4][4] = {{n, 0, 0, 0},
                          {0, n, 0, 0},
                          {0, 0, n, 0},
                          {0, 0, 0, 1}};
    void* pointer = malloc(sizeof(matrix));
    return pointer;
}

void* multiplyMatrices(float** first, float** second) {

    int r1 = sizeof *first / sizeof first[0];
    int c1 = sizeof *first[0] / sizeof first[0][0];
    int c2 = sizeof *second[0] / sizeof second[0][0];
    int result[64][10];
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    // Multiplying first and second matrices and storing it in result
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j) {
            for (int k = 0; k < c1; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
    void* pointer = malloc(sizeof(result));
    return pointer;
}
void *multiplyMatrixFloat(float* first[1][4], float* second) {
    int r1 = sizeof *first / sizeof first[0];
    int c1 = sizeof *first[0] / sizeof first[0][0];
    int result[1][4];
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < 1; ++j) {
            result[i][j] = 0;
        }
    }
    for (int i; i <r1; i++) {
        for (int j; j <c1; j++) {
            float value = *first[i][j];
            float multiplier = *second;
            result[i][j] = value * multiplier;
        }
    }
    void* pointer = malloc(sizeof(result));
    return pointer;
}
