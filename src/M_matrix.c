// Created by elcq6451 on 03/03/2023.
#include "../includes/M_matrix.h"
#include <stdlib.h>


void *translateMatrix(Point3 pos) {
    int i, j;

    float (*matrix)[4] = malloc(4 * sizeof(float[4]));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = 1;
    matrix[1][1] = 1;
    matrix[2][2] = 1;
    matrix[3][0] = pos.x;
    matrix[3][1] = pos.y;
    matrix[3][2] = pos.z;
    matrix[3][3] = 1;
    return matrix;
    /*{ {1,     0,      0,      0},
        {0,     1,      0,      0},
        {0,     0,      1,      0},
        {pos.x, pos.y,  pos.z,  1}} */

}

void *rotateXMatrix(float angle) {
    int i, j;

    float (*matrix)[4] = malloc(4 * sizeof(float[4]));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = 1;
    matrix[1][1] = M_cos(angle);
    matrix[1][2] = M_sin(angle);
    matrix[2][1] = -M_sin(angle);
    matrix[2][2] = M_cos(angle);
    matrix[3][3] = 1;
    /*{{1, 0,               0,              0},
       {0, M_cos(angle),    M_sin(angle),   0},
       {0, -M_sin(angle),   M_cos(angle),   0},
       {0, 0,               0,              1}} */
    return matrix;
}
void *rotateYMatrix(float angle) {
    int i, j;

    float (*matrix)[4] = malloc(4 * sizeof(float[4]));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = M_cos(angle);
    matrix[0][2] = -M_sin(angle);
    matrix[1][1] = 1;
    matrix[2][0] = M_sin(angle);
    matrix[2][2] = M_cos(angle);
    matrix[3][3] = 1;
    return matrix;
}
void *rotateZMatrix(float angle) {
    int i, j;

    float (*matrix)[4] = malloc(4 * sizeof(float[4]));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0]= M_cos(angle);
    matrix[0][1] = M_sin(angle);
    matrix[1][0] = -M_sin(angle);
    matrix[1][1] = M_cos(angle);
    matrix[2][2] = 1;
    matrix[3][3] = 1;
    /*float matrix[4][4] = {{cos(angle), sin(angle), 0, 0},
                          {-sin(angle), cos(angle), 0, 0},
                          {0, 0, 1, 0},
                          {0, 0, 0, 1}};*/
    return matrix;
}
void *scaleMatrix(float n) {
    int i, j;
    float (*matrix)[4] = malloc(4 * sizeof(float[4]));
    for(i = 0; i < 4; i++){
        for(j = 0; j < 4; j++) {
            matrix[i][j] = 0;
        }
    }
    matrix[0][0] = n; //{{n, 0, 0, 0},{0, n, 0, 0},{0, 0, n, 0},{0, 0, 0, 1}};
    matrix[1][1] = n;
    matrix[2][2] = n;
    matrix[3][3] = 1;
    return matrix;
}

void* multiplyMatrices(float** first, int r1, int c1, float** second, int c2) {
    int i, j, k;
    float (*result)[c2] = malloc(r1 * sizeof(float[c2]));

    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            result[i][j] = 0;
        }
    }

    for (i = 0; i < r1; ++i) {
        for (j = 0; j < c2; ++j) {
            for (k = 0; k < c1; ++k) {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }

    return result;
}
float* multiplyMatrixByScalar(float* matrix, int rows, int cols, float scalar) {
    float* result = malloc(rows * cols * sizeof(float));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i * cols + j] = matrix[i * cols + j] * scalar;
        }
    }
    return result;
}
