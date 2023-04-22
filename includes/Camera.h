#ifndef FOLDER_CAMERA_H
#define FOLDER_CAMERA_H

#include "./misc.h"
#include <fxcg/keyboard.h>
#include <fxcg/display.h>

typedef struct Camera {
    float position[4];
    float forward[4];
    float right[4];
    float up[4];
    float h_fov;
    float v_fov;
    float nearPlane;
    float farPlane;
    float movingSpeed;
    float rotatingSpeed;

    float anglePitch;
    float angleYaw;
    float angleRoll;
    void (*control) (struct Camera*);
}Camera;

Camera initializeCamera(struct Camera *inst, Point3F *position);
void control(Camera* inst);

#endif //FOLDER_CAMERA_H
