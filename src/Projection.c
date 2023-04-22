#include "../includes/Projection.h"

Projection *initProjection(struct Camera* Camera) {
    Projection* p = (Projection *) malloc(sizeof(Projection));
    p->NEAR = Camera->nearPlane;
    p->FAR = Camera->farPlane;
    p->RIGHT = M_tan(Camera->h_fov / 2);
    p->LEFT = -p->RIGHT;
    p->TOP = M_tan(Camera->v_fov / 2);
    p->BOTTOM = -p->BOTTOM;
    float array[4][4] = {{2 / (p->RIGHT - p->LEFT), 0, 0, 0},
                         {0, 2 / (p->TOP - p->BOTTOM), 0, 0},
                         {0, 0, (p->FAR + p->NEAR) / (p->FAR - p->NEAR), 1},
                         {0, 0, -2 * p->NEAR * p->FAR /  (p->FAR - p->NEAR), 0}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->projectionMatrix[i][j] = array[i][j];
        }
    }
    float array2[4][4] = {{LCD_WIDTH_PX / 2, 0, 0, 0},
                          {0, -(LCD_HEIGHT_PX / 2), 0, 0},
                          {0, 0, 1, 0},
                          {LCD_WIDTH_PX / 2, LCD_HEIGHT_PX / 2, 0, 1}};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            p->toScreenMatrix[i][j] = array2[i][j];
        }
    }
    return p;
}
