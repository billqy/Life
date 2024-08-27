#ifndef QUARK_H
#define QUARK_H

#include "include/raylib.h"
#include "include/raymath.h"

typedef struct _Quark {
    char type;
    Color color;
    Vector2 pos;
    Vector2 velo;
} Quark;

void GenerateQuarks(Quark quarks[]);
float DetermineAttraction(char selfType, char otherType);
void UpdateQuarks(Quark* quark, float frametime, Quark quarks[]);

#endif