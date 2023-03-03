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