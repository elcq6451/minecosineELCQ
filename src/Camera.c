#include "../includes/Camera.h"
#include "../includes/Math.h"

Camera initializeCamera(struct Camera *inst, Point3F *position) {
    Camera self;
    self.position[0] = position->x; self.position[1] = position->y; self.position[2] = position->z; self.position[3] = 1.0f;
    self.forward[0] = 0; self.forward[1] = 0; self.forward[2] = 1; self.forward[3] = 1;
    self.up[0] = 0; self.up[1] = 1; self.up[2] = 0; self.up[3] = 1;
    self.right[0] = 1; self.right[1] = 0; self.right[2] = 0; self.right[3] = 1;
    self.h_fov = 1.22173f;
    self.v_fov = self.h_fov * (LCD_HEIGHT_PX / LCD_WIDTH_PX);
    self.nearPlane = 0.1f;
    self.farPlane = 100;
    self.movingSpeed = 0.3;
    self.rotatingSpeed = 0.015;

    self.anglePitch = 0;
    self.angleYaw = 0;
    self.angleRoll = 0;
    self.control = &control;

    return self;
}

void control(Camera* inst) {
    int key;
    GetKey(&key);
    if(key == KEY_PRGM_6) {
        float** dPosition = multiplyMatrixByScalar((float**)inst->right,inst->movingSpeed, 1, 4);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] += *dPosition[i];
        }
    }
    else if(key == KEY_PRGM_8) {
        float** dPosition = multiplyMatrixByScalar((float**)inst->forward,inst->movingSpeed, 1, 4);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] += *dPosition[i];
        }
    }
    else if(key == KEY_PRGM_4) {

        float** dPosition = multiplyMatrixByScalar((float**)inst->right,inst->movingSpeed, 1, 4);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] -= *dPosition[i];
        }
    }
    else if(key == KEY_PRGM_5) {
        float** dPosition = multiplyMatrixByScalar((float**)inst->forward,inst->movingSpeed, 1, 4);
        for (int i=0; i < sizeof(inst->position) / sizeof(inst->position[0]); i ++) {
            inst->position[i] -= *dPosition[i];
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