#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>


typedef struct _Quark {
    char type;
    Vector2 pos;
    Vector2 velo;
} Quark;


const int sWidth = 1600;
const int sHeight = 1000;
const int quarkCount = 1500;
const float Gravity = 100;


void GenerateQuarks(Quark quarks[]) {
    for (int i = 0; i < quarkCount; i++) {
        int typeNum = GetRandomValue(1, 4);
        printf("%d", typeNum);
        char tempType;
        
        switch(typeNum) {
            case 1:
                tempType = 'Y';
                break;
            case 2:
                tempType = 'G';
                break;
            case 3:
                tempType = 'B';
                break;
            case 4:
                tempType = 'R';
                break;
        }
        
        Quark newQuark = { tempType, {GetRandomValue(100, 1500), GetRandomValue(100, 900)}, {0,0} };
        quarks[i] = newQuark;
    }   
}

void UpdateQuarks(Quark* quark, float frametime, Quark quarks[]) {
    quark->pos = Vector2Add(quark->pos, Vector2Scale(quark->velo, frametime));
    float F, fx, fy;
    
    for (int i = 0; i < quarkCount; i++) {
        float G = Gravity;

/* Interactions:
        YxY = 0     YxG = 0.4   YxB = -0.1      YxR = -0.5
        GxY = -0.2  GxG = 0.3   GxB = 0.1       GxR = -0.8
        BxY = 0.3   BxG = 0.6   BxB = -0.2      BxR = 1
        RxY = -1    RxG = -0.4  RxB = -.6       RxR = -0.1  */
        
        switch(quark->type) {
            case 'Y':
                switch(quarks[i].type) {
                    case 'Y':
                        G *= 0;
                        break;
                    case 'G':
                        G *= -0.6;
                        break;
                    case 'B':
                        G *= 0;
                        break;
                    case 'R':
                        G *= 0.8;
                        break;
                }
                break;
            case 'G':
                switch(quarks[i].type) {
                    case 'Y':
                        G *= 0;
                        break;
                    case 'G':
                        G *= -0.4;
                        break;
                    case 'B':
                        G *= 0;
                        break;
                    case 'R':
                        G *= 1;
                        break;
                }
                break;
            case 'B':
                switch(quarks[i].type) {
                    case 'Y':
                        G *= 0;
                        break;
                    case 'G':
                        G *= 0;
                        break;
                    case 'B':
                        G *= 0;
                        break;
                    case 'R':
                        G *= -0.3;
                        break;
                }
                break;
            case 'R':
                switch(quarks[i].type) {
                    case 'Y':
                        G *= -0.8;
                        break;
                    case 'G':
                        G *= -0.7;
                        break;
                    case 'B':
                        G *= 0.3;
                        break;
                    case 'R':
                        G *= 0.6;
                        break;
                }
                break;
        }
        
/*        if (quark->type == 'Y') {
            if (quarks[i].type == 'Y') {
                G *= 0;
            } else {
                G *= -1;
            }
        } else if (quark->type == 'R') {
            if (quarks[i].type == 'R') {
                G *= 1;
            } else {
                G *= 0;
            }
        }*/
        
        
        float dx = quarks[i].pos.x - quark->pos.x;
        float dy = quarks[i].pos.y - quark->pos.y;
        float d = sqrt((dx*dx) + (dy*dy));
         
        if (d > 0.01 && d < 300) {
            F = G * 1/d;
            fx = F * dx;
            fy = F * dy;
        }
        
        Vector2 accel = {fx * frametime, fy * frametime};
        quark->velo = Vector2Add(quark->velo, accel);
        quark->velo = Vector2Scale(quark->velo, 0.99);
    }
        
    if (quark->pos.x < 0 || quark->pos.x > sWidth) { quark->velo.x *= -1; }
    if (quark->pos.y < 0 || quark->pos.y > sHeight) { quark->velo.y *= -1; }  
}


int main() {
    Quark quarks[quarkCount]; 
    
    InitWindow(sWidth, sHeight, "Life");
    SetTargetFPS(60);
    
    GenerateQuarks(quarks);
    
    while (!WindowShouldClose()) {
        BeginDrawing();
        
        float frametime = GetFrameTime();
        
        for (int i = 0; i < quarkCount; i++) {
            UpdateQuarks(&quarks[i], frametime, quarks);
            
            if (quarks[i].type == 'Y') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 7, 7, YELLOW);
            } else if (quarks[i].type == 'G') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 7, 7, GREEN);
            } else if (quarks[i].type == 'B') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 7, 7, BLUE);
            } else if (quarks[i].type == 'R') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 7, 7, RED);
            }
        }
        
        ClearBackground(BLACK);
        
        EndDrawing();    
    }
    
    CloseWindow();
    
    return 0;
}

