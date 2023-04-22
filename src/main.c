#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdbool.h>
#include "../includes/GameEngine.h"


GameEngine gameEngine = {0};

bool PROGRAM_RUNNING = true;
bool EXIT_PROGRAM = false;



int main(void) {
    gameEngine = InitGameEngine(216, 384);
    int key;
    Bdisp_EnableColor(1);
    Bdisp_AllClr_VRAM();
    Bdisp_PutDisp_DD();

    while (PROGRAM_RUNNING == true) {
        if (EXIT_PROGRAM == true) {break;}
        GetKey(&key);
        if (key == KEY_CTRL_EXIT){
            EXIT_PROGRAM = true;
        }
        else if (key == KEY_CTRL_F1) {
            gameEngine.DrawLine(initPoint2I(2,2), initPoint2I(50,20), 0x5500);
        }
        else if (key == KEY_CTRL_F6) {
            Bdisp_AllClr_VRAM();
        }
    }
    return 0;
}
