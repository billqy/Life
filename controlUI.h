#ifndef CONTROLS_H
#define CONTROLS_H

#include "include/raygui.h"

typedef struct Button {
    Rectangle rect;
    Color color;
} Button;

typedef struct Label {
    Rectangle rect;
} Label;

typedef struct Panel {
    Rectangle rect;
    Color color;
} Panel;

typedef struct Slider {
    Rectangle rect;
    float* pValue;
    float value;
    float minVal;
    float maxVal;
} Slider;

void InitUI();
void DrawControlUI();
void UpdateSettings();

#endif