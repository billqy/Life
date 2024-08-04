#include <raylib.h>
#include <raymath.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>


typedef struct _Quark {
    char type;
    Vector2 pos;
    Vector2 velo;
} Quark;


const int sWidth = 1600;
const int sHeight = 1000;
const int quarkCount = 1000;
const float Gravity = 100;

Vector2 screen = {sWidth, sHeight};
Vector2 zeros = {0,0};


void GenerateQuarks(Quark quarks[]) {
    for (int i = 0; i < quarkCount; i++) {
        
        int typeNum = GetRandomValue(1, 4);
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
            default:
                tempType = 'Y';
                break;
        }
        
        Quark newQuark = { tempType, {GetRandomValue(100, 1500), GetRandomValue(100, 900)}, {0,0} };
        quarks[i] = newQuark;
    }   
}

float DetermineAttraction(char selfType, char otherType) {
    float modifier = 1;
    
    float interactionMatrix[4][4] = {
            {1, 0.1, 0, -0.1}, // YxY, YxG, YxB, YxR
            {-0.1, 1, 0.1, 0}, // GxY, GxG, GxB, GxR
            {0, -0.1, 1, 0.1}, // BxY, BxG, BxB, BxR
            {0.1, 0, -0.1, 1}  // RxY, RxG, RxB, RxR
    };
    
    switch (selfType) {
        case 'Y':
            switch (otherType) {
                case 'Y':
                    modifier = interactionMatrix[0][0];
                    break;
                case 'G':
                    modifier = interactionMatrix[0][1];
                    break;
                case 'B':
                    modifier = interactionMatrix[0][2];
                    break;
                case 'R':
                    modifier = interactionMatrix[0][3];
                    break;
                }
        case 'G':
            switch (otherType) {
                case 'Y':
                    modifier = interactionMatrix[1][0];
                    break;
                case 'G':
                    modifier = interactionMatrix[1][1];
                    break;
                case 'B':
                    modifier = interactionMatrix[1][2];
                    break;
                case 'R':
                    modifier = interactionMatrix[1][3];
                    break;
                }
        case 'B':
            switch (otherType) {
                case 'Y':
                    modifier = interactionMatrix[2][0];
                    break;
                case 'G':
                    modifier = interactionMatrix[2][1];
                    break;
                case 'B':
                    modifier = interactionMatrix[2][2];
                    break;
                case 'R':
                    modifier = interactionMatrix[2][3];
                    break;
                }
        case 'R':
            switch (otherType) {
                case 'Y':
                    modifier = interactionMatrix[3][0];
                    break;
                case 'G':
                    modifier = interactionMatrix[3][1];
                    break;
                case 'B':
                    modifier = interactionMatrix[3][2];
                    break;
                case 'R':
                    modifier = interactionMatrix[3][3];
                    break;
                }
            
    }
    
    return modifier;
}

void UpdateQuarks(Quark* quark, float frametime, Quark quarks[]) {
    quark->pos = Vector2Add(quark->pos, Vector2Scale(quark->velo, frametime));
    float F = 0, fx = 0, fy = 0;
    
    for (int i = 0; i < quarkCount; i++) {
        float G = Gravity;
        
        char selfType = quark->type;
        char otherType = quarks[i].type;
        
        float modifier = DetermineAttraction(selfType, otherType);
        
        float dx = quarks[i].pos.x - quark->pos.x;
        float dy = quarks[i].pos.y - quark->pos.y;
        float d = sqrt((dx*dx) + (dy*dy));
        
        G *= modifier;
        if (d > 0.01 && d < 300) {
            if (d < 15) { 
                if (G < 0) {
                    G = 10000;
                } else {
                    G = -10000;
                }
            }
            
            F = G * 1/d;
            fx = F * dx;
            fy = F * dy;
        }
        
        Vector2 accel = {fx * frametime, fy * frametime};
        quark->velo = Vector2Add(quark->velo, accel);
        quark->velo = Vector2Scale(quark->velo, 0.99);
    }
        
    if (quark->pos.x < 0 || quark->pos.x > sWidth) {
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo.x *= -1; 
    } else if (quark->pos.x > sWidth) {
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo.x *= -1; 
    }
    
    if (quark->pos.y < 0 || quark->pos.y > sHeight) { 
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo.y *= -1; 
    } else if (quark->pos.y > sHeight) {
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo.y *= -1;
    }
}


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
            
            if (quarks[i].type == 'Y') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, YELLOW);
            } else if (quarks[i].type == 'G') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, GREEN);
            } else if (quarks[i].type == 'B') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, BLUE);
            } else if (quarks[i].type == 'R') {
                DrawRectangle(quarks[i].pos.x, quarks[i].pos.y, 8, 8, RED);
            }
        }
        
        DrawFPS(10,10);
        DrawText(tQuarkLabel, 10, 35, 20, WHITE);
        ClearBackground(BLACK);
        
        EndDrawing();    
    }
    
    CloseWindow();
    
    return 0;
}

