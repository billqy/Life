#include "include/raylib.h"
#include "include/raymath.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "settings.h"
#include "quark.h"
//#include "controls.h"

int quarkCount = 1000;
int MIN_ATTRACTION_DISTANCE = 75;
int MAX_ATTRACTION_DISTANCE = 500;
int Gravity = 100;

Vector2 screen = {sWidth, 1000};
Vector2 zeros = {0,0};

int main() {
    Quark quarks[quarkCount]; 
    
    InitWindow(sWidth, sHeight, "Life");
    SetTargetFPS(60);
    
    GenerateQuarks(quarks);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        char tQuarkLabel[] = "Quarks: ";
        char tQuarkCount[10];
        itoa(quarkCount, tQuarkCount, 10);
        strcat(tQuarkLabel, tQuarkCount);
        
        float frametime = GetFrameTime();
        
        for (int i = 0; i < quarkCount; i++) {
            UpdateQuarks(&quarks[i], frametime, quarks);
            
            DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, quarks[i].color);
        }
        
        DrawFPS(10,10);
        DrawText(tQuarkLabel, 10, 35, 20, WHITE);
        ClearBackground(BLACK);
        
        EndDrawing();    
    }
    
    CloseWindow();
    
    return 0;
}

