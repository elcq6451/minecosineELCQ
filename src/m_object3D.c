// Created by elcq6451 on 03/03/2023.

#include "../includes/m_object3D.h"
#include "../includes/M_matrixFunctions.h"
#include <stdlib.h>

float vertexes[256][4] = {{0, 0, 0, 1},{0, 1, 0, 1},{1, 1, 0, 1},{1, 0, 0, 1},
                          {0, 0, 1, 1},{0, 1, 1, 1},{1, 1, 1, 1},{1, 0, 1, 1}};
float faces[256][4] = {{0, 1, 2, 3},{4, 5, 6, 7},{0, 4, 5, 1},{2, 3, 7, 6},{1, 2, 6, 5},{0, 3, 7, 4}};

void *translateObject(void *array ,Point3 pos) {
    array = multiplyMatrices(array, translateMatrix(pos));
    void *pointer = malloc(sizeof(array));
    return array;
}
