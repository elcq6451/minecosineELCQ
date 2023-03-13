// Created by elcq6451 on 11/03/2023.
#include <math.h>
#include <fxcg/keyboard.h>
#include "../includes/Camera.h"
#include "../includes/Miscellaneous.h"


Camera initCamera(GameVideo renderer, Point3 *position) {
    Camera self;
    self.renderer = renderer;
    self.position[0] = position->x; self.position[1] = position->y; self.position[2] = position->z; self.position[3] = 1.0f;
    self.forward[0][0] = 0; self.forward[0][1] = 0; self.forward[0][2] = 1; self.forward[0][3] = 1;
    self.up[0][0] = 0; self.up[0][1] = 1; self.up[0][2] = 0; self.up[0][3] = 1;
    self.right[0][0] = 1; self.right[0][1] = 0; self.right[0][2] = 0; self.right[0][3] = 1;
    self.h_fov = M_PI / 3;
    self.v_fov = self.h_fov * (renderer.HEIGHT / renderer.WIDTH);
    self.nearPlane = 0.1f;
    self.farPlane = 100;
    self.movingSpeed = 0.3;
    self.rotatingSped = 0.015;

    self.anglePitch = 0;
    self.angleYaw = 0;
    self.angleRoll = 0;
    self.control = &control;
    return self;
};

void control(struct Camera* inst) {
    int key;
    GetKey(&key);
    if(key == KEY_CTRL_F1) {
        return 0;
    };
}