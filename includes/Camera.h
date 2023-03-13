// Created by elcq6451 on 11/03/2023.

#ifndef FOLDER_CAMERA_H
#define FOLDER_CAMERA_H
#include "../includes/GameEngine.h"
typedef struct Camera Camera;
struct Camera {
    GameVideo renderer;
    float position[4];
    float forward[1][4];
    float up[1][4];
    float right[1][4];
    float h_fov;
    float v_fov;
    float nearPlane;
    float farPlane;
    float movingSpeed;
    float rotatingSped;

    float anglePitch;
    float angleYaw;
    float angleRoll;
    void (*control) (struct Camera *);

};

void control(struct Camera* inst);
#endif //FOLDER_CAMERA_H
