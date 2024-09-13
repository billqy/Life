#include "quark.h"

#include "settings.h"
#include <math.h>


void GenerateQuarks(Quark quarks[]) {
    for (int i = 0; i < MAX_QUARK_COUNT; i++) {
        
        int typeNum = GetRandomValue(1, 4);
        char tempType;
        Color color;
        
        switch(typeNum) {
            case 1: 
                tempType = 'Y';
                color = YELLOW;
                break;
            case 2:
                tempType = 'G';
                color = GREEN;
                break;
            case 3:
                tempType = 'B';
                color = BLUE;
                break;
            case 4:
                tempType = 'R';
                color = RED;
                break;
            default:
                tempType = 'Y';
                color = YELLOW;
                break;
        }
        
        Quark newQuark = { tempType, color, {GetRandomValue(200, sHeight-200), GetRandomValue(200, sWidth-200)}, {0,0} }; 
        quarks[i] = newQuark;
    }   
}

float DetermineAttraction(char selfType, char otherType) {
    float modifier = 1;
    
    float interactionMatrix[4][4] = {
            /*{1, 0.5, 0, -0.4}, // YxY, YxG, YxB, YxR
            {-0.4, 1, 0.5, 0}, // GxY, GxG, GxB, GxR
            {0, -0.4, 1, 0.5}, // BxY, BxG, BxB, BxR
            {0.4, 0, -0.4, 1}  // RxY, RxG, RxB, RxR*/
            
            {1, 0.2, 0, 0}, // YxY, YxG, YxB, YxR
            {0, 1, 0.2, 0}, // GxY, GxG, GxB, GxR
            {0, 0, 1, 0.2}, // BxY, BxG, BxB, BxR
            {0, 0, 0, 1}  // RxY, RxG, RxB, RxR*/
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
            break;
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
            break;
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
            break;
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
            break;
    }
    
    return modifier;
}

void UpdateQuarks(Quark* quark, float frametime, Quark quarks[]) {
    for (int i = 0; i < QUARK_COUNT; i++) {
        float F = 0, fx = 0, fy = 0;
        float G = GRAVITY * 0.01;
        
        char selfType = quark->type;
        char otherType = quarks[i].type;
        
        float modifier = DetermineAttraction(selfType, otherType);
        //float modifier = 1;
        
        float dx = quarks[i].pos.x - quark->pos.x;
        float dy = quarks[i].pos.y - quark->pos.y;
        float d = sqrt((dx*dx) + (dy*dy));
        
        if (d < 1.0) { d = 1.0; }
        
        if (d < MAX_ATTRACTION_DISTANCE) {

            if (d < MIN_ATTRACTION_DISTANCE) {
                //F = (d*G*2 / MIN_ATTRACTION_DISTANCE) - (G*2);
                F = -0.001 * G * pow( (d - MIN_ATTRACTION_DISTANCE), 2);
            } else {
                int midpoint = (MAX_ATTRACTION_DISTANCE + MIN_ATTRACTION_DISTANCE) / 2;
                
                if (d < midpoint) {
                    F = G * modifier * ((d-MIN_ATTRACTION_DISTANCE) / MIN_ATTRACTION_DISTANCE);
                } else {
                    F = G * modifier * -((d-MAX_ATTRACTION_DISTANCE) / MIN_ATTRACTION_DISTANCE);
                }
            }
            
            fx = F * (dx / d);
            fy = F * (dy / d);
        }
       
        Vector2 accel = {fx * frametime, fy * frametime};
        quark->velo = Vector2Add(quark->velo, accel);
        quark->velo = Vector2Scale(quark->velo, 0.995);
        quark->pos = Vector2Add(quark->pos, Vector2Scale(quark->velo, frametime));
    }
        
    if (quark->pos.x < 0) {
        quark->pos = (Vector2) { sWidth, quark->pos.y };
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo = (Vector2) { quark->velo.x - 5 , quark->velo.y };
    } else if (quark->pos.x > sWidth) {
        quark->pos = (Vector2) { 0, quark->pos.y };
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo = (Vector2) { quark->velo.x + 5 , quark->velo.y };
    }
    if (quark->pos.y < 0) { 
        quark->pos = (Vector2) { quark->pos.x, sHeight };
        quark->pos = Vector2Clamp(quark->pos, zeros, screen);
        quark->velo = (Vector2) { quark->velo.x , quark->velo.y - 5 };
    } else if (quark->pos.y > sHeight) {
        quark->pos = (Vector2) { quark->pos.x, 0 };
        quark->pos = Vector2Clamp(quark->pos, zeros, screen); 
        quark->velo = (Vector2) { quark->velo.x , quark->velo.y + 5 };        
    }
}