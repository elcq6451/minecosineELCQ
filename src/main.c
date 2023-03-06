#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdio.h>
#include <stdbool.h>
#include "../includes/v_gameVideo.h"
#include "../includes/Miscellaneous.h"



bool PROGRAM_RUNNING = true;
bool EXIT_PROGRAM = false;



int main(void) {
    struct GameVideo gameVideo;
    int key;
    Bdisp_EnableColor(1);
    Bdisp_AllClr_VRAM();

    while (PROGRAM_RUNNING == true) {
        if (EXIT_PROGRAM == true) {break;}
        key = GetKey();
        Point2 array[2];
        gameVideo.initPoint2 = initPoint2();
        array[0] = gameVideo.initPoint2(10,250);
        array[1] = gameVideo.initPoint2(250,50);
        gameVideo.DL = DrawLine;
        if (key == KEY_CTRL_F1) {
            gameVideo.DL(array[0],array[1], 0x0ff0);
        }
        else if (key == KEY_CTRL_F5) {
            PrintXY(1,1,"Table",1,1);
        }
        else if (key == KEY_CTRL_F6) {
            Bdisp_AllClr_VRAM();
        }
    }
 
    return 0;
}
