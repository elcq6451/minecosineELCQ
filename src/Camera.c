// Created by elcq6451 on 11/03/2023.
#include "../includes/math.h"
#include <fxcg/keyboard.h>
#include "../includes/Camera.h"
#include "../includes/Miscellaneous.h"
#include "../includes/M_matrix.h"
#include "../includes/GameEngine.h"


Camera initCamera(Point3 *position) {
    Camera self;
    GameEngine GE;
    self.position[0] = position->x; self.position[1] = position->y; self.position[2] = position->z; self.position[3] = 1.0f;
    self.forward[0][0] = 0; self.forward[0][1] = 0; self.forward[0][2] = 1; self.forward[0][3] = 1;
    self.up[0][0] = 0; self.up[0][1] = 1; self.up[0][2] = 0; self.up[0][3] = 1;
    self.right[0][0] = 1; self.right[0][1] = 0; self.right[0][2] = 0; self.right[0][3] = 1;
    self.h_fov = 1.22173f;
    self.v_fov = self.h_fov * (GE.HEIGHT / GE.WIDTH);
    self.nearPlane = 0.1f;
    self.farPlane = 100;
    self.movingSpeed = 0.3;
    self.rotatingSpeed = 0.015;

    self.anglePitch = 0;
    self.angleYaw = 0;
    self.angleRoll = 0;
    self.control = &control;
    return self;
};

void control(struct Camera* inst) {
    int key;
    GetKey(&key);
    if(key == KEY_PRGM_6) {
        void* rightptr = &inst->right;
        float* dPosition = multiplyMatrixFloat(rightptr, &inst->movingSpeed);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] += dPosition[i];
        }
    }
    else if(key == KEY_PRGM_8) {
        void* forwardptr = &inst->forward;
        float* dPosition = multiplyMatrixFloat(forwardptr, &inst->movingSpeed);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] += dPosition[i];
        }
    }
    else if(key == KEY_PRGM_4) {
        void* rightptr = &inst->right;
        float* dPosition = multiplyMatrixFloat(rightptr, &inst->movingSpeed);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] -= dPosition[i];
        }
    }
    else if(key == KEY_PRGM_5) {
        void* forwardptr = &inst->forward;
        float* dPosition = multiplyMatrixFloat(forwardptr, &inst->movingSpeed);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] -= dPosition[i];
        }
    }
    else if (key == KEY_CTRL_LEFT) {
        inst->angleYaw = 0 - inst->rotatingSpeed;
    }
    else if (key == KEY_CTRL_RIGHT) {
        inst->angleYaw = inst->rotatingSpeed;
    }
    else if (key == KEY_CTRL_UP) {
        inst->anglePitch = 0 - inst->rotatingSpeed;
    }
    else if (key == KEY_CTRL_DOWN) {
        inst->anglePitch = inst->rotatingSpeed;
    }
}