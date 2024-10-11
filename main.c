#ifndef RAYGUI_IMPLEMENTATION
#define RAYGUI_IMPLEMENTATION
#endif

#include "include/raylib.h"
#include "include/raymath.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#include "settings.h"
#include "quark.h"
#include "controlUI.h"


// SIM-WIDE SETTINGS
int MAX_QUARK_COUNT = 2000;
int QUARK_COUNT = 1000;
int MIN_ATTRACTION_DISTANCE = 100;
int MAX_ATTRACTION_DISTANCE = 500;
int GRAVITY = 100;
float INTERACTION_MATRIX[4][4] = {
    {0, 0, 0, 0}, // YxY, YxG, YxB, YxR
    {0, 0, 0, 0}, // GxY, GxG, GxB, GxR
    {0, 0, 0, 0}, // BxY, BxG, BxB, BxR
    {0, 0, 0, 0}  // RxY, RxG, RxB, RxR*/
};
int CLEARED = 0;
int GENERATE = 0;

Vector2 screen = {sWidth, sHeight};
Vector2 zeros = {0,0};

int main() {
    Quark quarks[MAX_QUARKS]; 
    
    InitWindow(sWidth, sHeight, "Life");
    SetTargetFPS(60);
    
    GenerateQuarks(quarks);
    InitUI();
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        char tQuarkLabel[] = "Quarks: ";
        char tQuarkCount[10];
        itoa(QUARK_COUNT, tQuarkCount, 10);
        strcat(tQuarkLabel, tQuarkCount);
        
        //Sim
        float frametime = GetFrameTime();

        if (GENERATE) {
            GenerateQuarks(quarks);
            GENERATE = 0;
        }
        
        for (int i = 0; i < QUARK_COUNT; i++) {
            UpdateQuarks(&quarks[i], frametime, quarks);
            
            DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, quarks[i].color);
        }
        
        DrawFPS(10,10);
        DrawText(tQuarkLabel, 10, 35, 20, WHITE);
        DrawControlUI();
        UpdateSettings();
        ClearBackground(BLACK);
        
        EndDrawing();    
    }
    
    CloseWindow();
    
    return 0;
}

