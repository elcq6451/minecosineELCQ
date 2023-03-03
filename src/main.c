#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdio.h>
#include "../includes/v_gameVideo.h"

int main(void) {
    int key;
    Bdisp_EnableColor(1);
    Bdisp_AllClr_VRAM();
    //PrintXY(1, 1, "  Hello!", TEXT_MODE_NORMAL, TEXT_COLOR_RED);




    while (1) {
        GetKey(&key);

        if (key == KEY_CTRL_EXE) {
            break;
        }
        else if (key == KEY_CTRL_F4) {
            Point2 var1;
            var1.x = 0;
            var1.y = 36;
            Point2 var2;
            var2.x = 50;
            var2.y = 200;
            DrawLine(var1, var2, 0xff00);
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
