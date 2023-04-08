#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdbool.h>
#include "../includes/GameEngine.h"

GameEngine gameEngine = InitGameEngine(216, 384);

bool PROGRAM_RUNNING = true;
bool EXIT_PROGRAM = false;



int main(void) {
    int key;
    Bdisp_EnableColor(1);
    Bdisp_AllClr_VRAM();

    while (PROGRAM_RUNNING == true) {
        if (EXIT_PROGRAM == true) {break;}
        GetKey(&key);
        if (key == KEY_CTRL_F1) {
            gameEngine.DrawLine(initPoint2I(2,2), initPoint2I(50,50), 0x5500);
        }
        else if (key == KEY_CTRL_F2){
            PrintXY(100,100,"me", 2 ,2);
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
