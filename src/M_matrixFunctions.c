// Created by elcq6451 on 03/03/2023.

#include "../includes/M_matrixFunctions.h"

void *translateMatrix(Point3 pos) {
    int matrix[4][4] = {{1, 0, 0, 0},
                        {0, 1, 0, 0},
                        {0, 0, 1, 0},
                        {pos.x, pos.y, pos.z, 1}};
    return *matrix;
}

void *rotateXMatrix(float angle) {
    float matrix[4][4] = {{1, 0, 0, 0},
                          {0, cos(angle), sin(angle), 0},
                          {0, -sin(angle), cos(angle), 0},
                          {0, 0, 0, 1}};
    return *matrix;
}
void *rotateYMatrix(float angle) {
    float matrix[4][4] = {{cos(angle), 0, -sin(angle), 0},
                          {0, 1, 0, 0},
                          {sin(angle), 0, cos(angle), 0},
                          {0, 0, 0, 1}};
    return *matrix;
}
void *rotateZMatrix(float angle) {
    float matrix[4][4] = {{cos(angle), sin(angle), 0, 0},
                          {-sin(angle), cos(angle), 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};
    return *matrix;
}
void *scaleMatrix(float n) {
    float matrix[4][4] = {{n, 0, 0, 0},
                          {0, n, 0, 0},
                          {0, 0, n, 0},
                          {0, 0, 0, 1}};
    return *matrix;
}