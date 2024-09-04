#ifndef CONTROLS_H
#define CONTROLS_H

#include "include/raygui.h"

typedef struct Button {
    Rectangle rect;
    Color color;
} Button;

typedef struct Panel {
    Rectangle rect;
    Color color;
} Panel;

void InitUI();
void DrawControlUI();

#endif