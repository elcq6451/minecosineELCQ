#include <fxcg/display.h>
#include <fxcg/keyboard.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../includes/Miscellaneous.h"
#include "../includes/M_matrixFunctions.h"
#include "../includes/GameEngine.h"



bool PROGRAM_RUNNING = true;
bool EXIT_PROGRAM = false;



int main(void) {
    int key;
    Bdisp_EnableColor(1);
    Bdisp_AllClr_VRAM();
    GameEngine gameEngine = initGameEngine();

    while (PROGRAM_RUNNING == true) {
        if (EXIT_PROGRAM == true) {break;}
        GetKey(&key);
        Point2 array[2];
        array[0] = gameEngine.initPoint2(&gameEngine.GV, 10, 250);
        array[1] = gameEngine.initPoint2(&gameEngine.GV, 250, 50);
        if (key == KEY_CTRL_F1) {
            gameEngine.DrawLine(&gameEngine ,array[0],array[1], 0x0ff0);
        }
        else if (key == KEY_CTRL_F2){
            float array[4][4] = {{0,10,1,1},{0,10,1,1},{0,10,1,1},{0,10,1,1},};
            void* result = multiplyMatrices(&array, rotateXMatrix(90));
            PrintXY(100,100,result, 2 ,2);
            free(result);

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
