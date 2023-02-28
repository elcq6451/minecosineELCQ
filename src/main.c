#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdio.h>
#include "../includes/v_gameVideo.h"

void main(void) {
    int key;
    int WIDTH;
     
    Bdisp_AllClr_VRAM();
    SetBackGround(1);
    PrintXY(1, 1, "  Hello!", TEXT_MODE_NORMAL, TEXT_COLOR_RED);


    // set pixel at a coordinate
    int y = 150;
    int x = 30;
    unsigned  short col = 2;
    unsigned short *v = GetVRAMAddress();
    v+=y*384+x;
    *v=col;

    while (1) {
        GetKey(&key);

        if (key == KEY_CTRL_EXE) {
            break;
        }
    }
 
    return;
}
