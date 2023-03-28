// Created by elcq6451 on 28/03/2023.
#include "../includes/math.h"


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
