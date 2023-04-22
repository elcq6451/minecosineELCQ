#include "../includes/Math.h"

float** multiplyMatrix(float** A, float** B, int rowsA, int colsA, int rowsB, int colsB) {
    if (colsA != rowsB) {
        return NULL;
    }

    float** C = (float**) malloc(rowsA * sizeof(float*));
    for (int i = 0; i < rowsA; i++) {
        C[i] = (float*) malloc(colsB * sizeof(float));
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            C[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return C;
}

float** multiplyMatrixByScalar(float** A, float scalar, int rows, int cols) {
    float** C = (float**) malloc(rows * sizeof(float*));
    for (int i = 0; i < rows; i++) {
        C[i] = (float*) malloc(cols * sizeof(float));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            C[i][j] = scalar * A[i][j];
        }
    }

    return C;
}


int factorial(int x) {
    int number = 1;
    for (int i=1; i <= x; i++) {
        number *= i;
    }
    return number;
}
float M_pow(float base, float power) {
    float val = 1;
    for(int i = 0; i < power; i++) {
        val *= base;
    }
    return val;
}

float M_sin(float x) {
    float value = x - (M_pow(x,3) / factorial(3)) + (M_pow(x, 5) / factorial(5)) - (M_pow(x,7) / factorial(7)) + (M_pow(x,9) / factorial(9)) - (M_pow(x,11) / factorial(11));
    return value;
}
float M_cos(float x) {
    float value = 1 - (M_pow(x,2) / factorial(2)) + (M_pow(x,4) / factorial(4)) - (M_pow(x,6) / factorial(6)) + (M_pow(x,8) / factorial(8)) - (M_pow(x,10) / factorial(10));
    return value;
}
float M_tan(float x) {
    float value = M_sin(x) / M_cos(x);
    return value;
}
