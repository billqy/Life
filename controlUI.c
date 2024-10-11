#include "controlUI.h"

#include <stdlib.h>
#include <stdio.h>
#include "settings.h"

// CONTROLS TO BE ADDED:
// Mouse1 Attraction Force
// Mouse2 Repulsion Force

int RULES_TOGGLE = 0;

Button RulesButton;
Panel BackgroundPanel;

Label QuarkLabel;
Slider QuarkSlider;
Label GravityLabel;
Slider GravitySlider;

Label RedPercentLabel;
Slider RedPercentSlider;
Label YellowPercentLabel;
Slider YellowPercentSlider;
Label GreenPercentLabel;
Slider GreenPercentSlider;
Label BluePercentLabel;
Slider BluePercentSlider;

Label MinAttractionLabel;
Slider MinAttractionSlider;
Label MaxAttractionLabel;
Slider MaxAttractionSlider;

Label InteractionTitleLabel;
Label InteractionXLabel;
Label InteractionY1Label;
Label InteractionY2Label;
Label InteractionY3Label;
Label InteractionY4Label;

Button YxY;
Button YxG;
Button YxB;
Button YxR;

Button GxY;
Button GxG;
Button GxB;
Button GxR;

Button BxY;
Button BxG;
Button BxB;
Button BxR;

Button RxY;
Button RxG;
Button RxB;
Button RxR;

Label PresetsLabel;
Button SnakePresetButton;
Button AtomPresetButton;
Button Preset3Button;

Label FunctionsLabel;
Button ClearButton;
Button ResetButton;
Button GenerateButton;

void InitUI() {
    GuiSetAlpha(0.7);
    int STD_LABEL_W = 200;
    int STD_LABEL_H = 15;
    float STD_PAD = 35;

    //GuiLoadStyle("dark.rgs");

    Rectangle RulesRect = {20, sHeight/2 - 50, 50, 100};
    Rectangle BackgroundPanelRect = {75, 75, 300, sHeight - 150};

    RulesButton.rect = RulesRect;
    BackgroundPanel.rect = BackgroundPanelRect;

    // Quarks
    QuarkLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 40, STD_LABEL_W, STD_LABEL_H};
    QuarkSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 5, BackgroundPanelRect.y + 60, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    QuarkSlider.pValue = &(QuarkSlider.value);
    QuarkSlider.value = QUARK_COUNT;
    QuarkSlider.minVal = 50;
    QuarkSlider.maxVal = 2000;

    // Gravity
    GravityLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 100, STD_LABEL_W, STD_LABEL_H};
    GravitySlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 5, BackgroundPanelRect.y + 120, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    GravitySlider.pValue = &(GravitySlider.value);
    GravitySlider.value = GRAVITY;
    GravitySlider.minVal = 50;
    GravitySlider.maxVal = 200;

    // Ratios
    // RedPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 160, STD_LABEL_W, STD_LABEL_H};
    // RedPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 180, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    // RedPercentSlider.pValue = &(RedPercentSlider.value);
    // RedPercentSlider.value = 25;
    // RedPercentSlider.minVal = 0;
    // RedPercentSlider.maxVal = 100;

    // YellowPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 220, STD_LABEL_W, STD_LABEL_H};
    // YellowPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 240, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    // YellowPercentSlider.pValue = &(YellowPercentSlider.value);
    // YellowPercentSlider.value = 25;
    // YellowPercentSlider.minVal = 0;
    // YellowPercentSlider.maxVal = 100;

    // GreenPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 280, STD_LABEL_W, STD_LABEL_H};
    // GreenPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 300, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    // GreenPercentSlider.pValue = &(GreenPercentSlider.value);
    // GreenPercentSlider.value = 25;
    // GreenPercentSlider.minVal = 0;
    // GreenPercentSlider.maxVal = 100;

    // BluePercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 340, STD_LABEL_W, STD_LABEL_H};
    // BluePercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 360, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    // BluePercentSlider.pValue = &(BluePercentSlider.value);
    // BluePercentSlider.value = 25;
    // BluePercentSlider.minVal = 0;
    // BluePercentSlider.maxVal = 100;

    // Attraction Distances
    MinAttractionLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD - 20, BackgroundPanelRect.y + 190, STD_LABEL_W, STD_LABEL_H};
    MinAttractionSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 5, BackgroundPanelRect.y + 210, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    MinAttractionSlider.pValue = &(MinAttractionSlider.value);
    MinAttractionSlider.value = 100;
    MinAttractionSlider.minVal = 25;
    MinAttractionSlider.maxVal = 300;

    MaxAttractionLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD - 50, BackgroundPanelRect.y + 250, STD_LABEL_W, STD_LABEL_H};
    MaxAttractionSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 5, BackgroundPanelRect.y + 270, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    MaxAttractionSlider.pValue = &(MaxAttractionSlider.value);
    MaxAttractionSlider.value = 500;
    MaxAttractionSlider.minVal = 350;
    MaxAttractionSlider.maxVal = 800;

    // Interaction Matrix
    InteractionTitleLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD - 50, BackgroundPanelRect.y + 370, STD_LABEL_W, STD_LABEL_H};
    InteractionXLabel.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 395, STD_LABEL_W + 10, STD_LABEL_H};
    InteractionY1Label.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 440, STD_LABEL_W, STD_LABEL_H};
    InteractionY2Label.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 485, STD_LABEL_W, STD_LABEL_H};
    InteractionY3Label.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 530, STD_LABEL_W, STD_LABEL_H};
    InteractionY4Label.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 575, STD_LABEL_W, STD_LABEL_H};

    int STD_IM = 40;

    YxY.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 30, BackgroundPanelRect.y + 425, STD_IM, STD_IM};
    YxG.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 80, BackgroundPanelRect.y + 425, STD_IM, STD_IM};
    YxB.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 130, BackgroundPanelRect.y + 425, STD_IM, STD_IM};
    YxR.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 180, BackgroundPanelRect.y + 425, STD_IM, STD_IM};

    GxY.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 30, BackgroundPanelRect.y + 470, STD_IM, STD_IM};
    GxG.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 80, BackgroundPanelRect.y + 470, STD_IM, STD_IM};
    GxB.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 130, BackgroundPanelRect.y + 470, STD_IM, STD_IM};
    GxR.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 180, BackgroundPanelRect.y + 470, STD_IM, STD_IM};

    BxY.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 30, BackgroundPanelRect.y + 515, STD_IM, STD_IM};
    BxG.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 80, BackgroundPanelRect.y + 515, STD_IM, STD_IM};
    BxB.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 130, BackgroundPanelRect.y + 515, STD_IM, STD_IM};
    BxR.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 180, BackgroundPanelRect.y + 515, STD_IM, STD_IM};

    RxY.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 30, BackgroundPanelRect.y + 560, STD_IM, STD_IM};
    RxG.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 80, BackgroundPanelRect.y + 560, STD_IM, STD_IM};
    RxB.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 130, BackgroundPanelRect.y + 560, STD_IM, STD_IM};
    RxR.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 180, BackgroundPanelRect.y + 560, STD_IM, STD_IM};

    YxY.val = INTERACTION_MATRIX[0][0];
    YxG.val = INTERACTION_MATRIX[0][1];
    YxB.val = INTERACTION_MATRIX[0][2];
    YxR.val = INTERACTION_MATRIX[0][3];
    GxY.val = INTERACTION_MATRIX[1][0];
    GxG.val = INTERACTION_MATRIX[1][1];
    GxB.val = INTERACTION_MATRIX[1][2];
    GxR.val = INTERACTION_MATRIX[1][3];
    BxY.val = INTERACTION_MATRIX[2][0];
    BxG.val = INTERACTION_MATRIX[2][1];
    BxB.val = INTERACTION_MATRIX[2][2];
    BxR.val = INTERACTION_MATRIX[2][3];
    RxY.val = INTERACTION_MATRIX[3][0];
    RxG.val = INTERACTION_MATRIX[3][1];
    RxB.val = INTERACTION_MATRIX[3][2];
    RxR.val = INTERACTION_MATRIX[3][3];

    // Presets (Snake, Atom, Placeholder)
    PresetsLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 650, STD_LABEL_W, STD_LABEL_H};
    SnakePresetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD - 20, BackgroundPanelRect.y + 670, 80, 40};
    AtomPresetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 70, BackgroundPanelRect.y + 670, 80, 40};
    Preset3Button.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 160, BackgroundPanelRect.y + 670, 80, 40};

    // Functions (Clear, Reset, Generate)
    FunctionsLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 80, STD_LABEL_W, STD_LABEL_H};
    ClearButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD - 20, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 60, 120, 40};
    ResetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 120, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 60, 120, 40};
    GenerateButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 20, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 15, 200, 40};

    return;
}


void DetermineButtonColor(float cVal, Button* button) {
    int color = 0xFFFFFFFF;

    if ( (cVal - -1 ) < 0.0001 ) {color = 0xFF2D00FF;}

    else if ( (cVal - -0.8) < 0.0001 ) {color = 0xFF502BFF;}

    else if ( (cVal - -0.6) < 0.0001 ) {color = 0xFF7557FF;}

    else if ( (cVal - -0.4) < 0.0001 ) {color = 0xFFA38FFF;}

    else if ( (cVal - -0.2) < 0.0001 ) {color = 0xFFCBBFFF;}

    else if ( (cVal - 0) < 0.0001 ) {color = 0xFFFFFFFF;}

    else if ( (cVal - 0.2) < 0.0001 ) {color = 0xC7FFBFFF;}

    else if ( (cVal - 0.4) < 0.0001 ) {color = 0xA3FF96FF;}

    else if ( (cVal - 0.6) < 0.0001 ) {color = 0x7AFF67FF;}

    else if ( (cVal - 0.8) < 0.0001 ) {color = 0x42FF28FF;}

    else if( (cVal - 1) < 0.0001 ) {color = 0x1FFF00FF;}

    if (cVal < 0.01 && cVal > -0.01) { cVal = 0.0; }
    sprintf(button->label, "%.1f", cVal);

    GuiSetStyle(DEFAULT, TEXT_COLOR_NORMAL, 0x000000FF); // black
    GuiSetStyle(DEFAULT, TEXT_COLOR_FOCUSED, 0x000000FF); // black
    GuiSetStyle(DEFAULT, BASE_COLOR_NORMAL, color);
    GuiSetStyle(DEFAULT, BASE_COLOR_FOCUSED, color);
}

void DrawControlUI() {
    //GuiLoadStyleDefault();
    GuiSetStyle(DEFAULT, TEXT_SIZE, 12);

    if (GuiButton(RulesButton.rect, "RULES")) {
        if (RULES_TOGGLE) {
            RULES_TOGGLE = 0;
        } else {
            RULES_TOGGLE = 1;
        }
    }

    if (RULES_TOGGLE) {
        GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
        GuiPanel(BackgroundPanel.rect, "SIM RULES");

        GuiLabel(QuarkLabel.rect, "Quarks");
        GuiSlider(QuarkSlider.rect, "50", "2000", QuarkSlider.pValue, QuarkSlider.minVal, QuarkSlider.maxVal);

        GuiLabel(GravityLabel.rect, "Gravity");
        GuiSlider(GravitySlider.rect, "50", "200", GravitySlider.pValue, GravitySlider.minVal, GravitySlider.maxVal);

        // GuiLabel(RedPercentLabel.rect, "Red %");
        // GuiSlider(RedPercentSlider.rect, "0", "100", RedPercentSlider.pValue, RedPercentSlider.minVal, RedPercentSlider.maxVal);

        // GuiLabel(YellowPercentLabel.rect, "Yellow %");
        // GuiSlider(YellowPercentSlider.rect, "0", "100", YellowPercentSlider.pValue, YellowPercentSlider.minVal, YellowPercentSlider.maxVal);

        // GuiLabel(GreenPercentLabel.rect, "Green %");
        // GuiSlider(GreenPercentSlider.rect, "0", "100", GreenPercentSlider.pValue, GreenPercentSlider.minVal, GreenPercentSlider.maxVal);

        // GuiLabel(BluePercentLabel.rect, "Blue %");
        // GuiSlider(BluePercentSlider.rect, "0", "100", BluePercentSlider.pValue, BluePercentSlider.minVal, BluePercentSlider.maxVal);

        GuiLabel(MinAttractionLabel.rect, "Min Distance");
        GuiSlider(MinAttractionSlider.rect, "25", "300", MinAttractionSlider.pValue, MinAttractionSlider.minVal, MinAttractionSlider.maxVal);

        GuiLabel(MaxAttractionLabel.rect, "Max Force Radius");
        GuiSlider(MaxAttractionSlider.rect, "350", "800", MaxAttractionSlider.pValue, MaxAttractionSlider.minVal, MaxAttractionSlider.maxVal);

        GuiLabel(InteractionTitleLabel.rect, "Interaction Matrix");
        GuiLabel(InteractionXLabel.rect, "x     Y     G     B     R");
        GuiLabel(InteractionY1Label.rect, "Y");
        GuiLabel(InteractionY2Label.rect, "G");
        GuiLabel(InteractionY3Label.rect, "B");
        GuiLabel(InteractionY4Label.rect, "R");

// GuiValueBox(Rectangle bounds, const char *text, int *value, int minValue, int maxValue, bool editMode); // Value Box control, updates input text with numbers
// GuiValueBoxFloat(Rectangle bounds, const char *text, char *textValue, float *value, bool editMode); // Value box control for float values

        DetermineButtonColor(YxY.val, &YxY);
        if (GuiButton(YxY.rect, YxY.label)) {
            YxY.val += 0.2;

            if ( YxY.val > 1) {
                YxY.val = -1;
            }    
        }

        DetermineButtonColor(YxG.val, &YxG);
        if (GuiButton(YxG.rect, YxG.label)) {
            YxG.val += 0.2;

            if ( YxG.val > 1) {
                YxG.val = -1;
            }
        }

        DetermineButtonColor(YxB.val, &YxB);
        if (GuiButton(YxB.rect, YxB.label)) {
            YxB.val += 0.2;

            if ( YxB.val > 1) {
                YxB.val = -1;
            }
        }

        DetermineButtonColor(YxR.val, &YxR);
        if (GuiButton(YxR.rect, YxR.label)) {
            YxR.val += 0.2;

            if ( YxR.val > 1) {
                YxR.val = -1;
            }
        }

        DetermineButtonColor(GxY.val, &GxY);
        if (GuiButton(GxY.rect, GxY.label)) {
            GxY.val += 0.2;

            if ( GxY.val > 1) {
                GxY.val = -1;
            }
        }

        DetermineButtonColor(GxG.val, &GxG);
        if (GuiButton(GxG.rect, GxG.label)) {
            GxG.val += 0.2;

            if ( GxG.val > 1) {
                GxG.val = -1;
            }
        }

        DetermineButtonColor(GxB.val, &GxB);
        if (GuiButton(GxB.rect, GxB.label)) {
            GxB.val += 0.2;

            if ( GxB.val > 1) {
                GxB.val = -1;
            }
        }

        DetermineButtonColor(GxR.val, &GxR);
        if (GuiButton(GxR.rect, GxR.label)) {
            GxR.val += 0.2;

            if ( GxR.val > 1) {
                GxR.val = -1;
            }
        }

        DetermineButtonColor(BxY.val, &BxY);
        if (GuiButton(BxY.rect, BxY.label)) {
            BxY.val += 0.2;

            if ( BxY.val > 1) {
                BxY.val = -1;
            }
        }

        DetermineButtonColor(BxG.val, &BxG);
        if (GuiButton(BxG.rect, BxG.label)) {
            BxG.val += 0.2;

            if ( BxG.val > 1) {
                BxG.val = -1;
            }
        }

        DetermineButtonColor(BxB.val, &BxB);
        if (GuiButton(BxB.rect, BxB.label)) {
            BxB.val += 0.2;

            if ( BxB.val > 1) {
                BxB.val = -1;
            }
        }

        DetermineButtonColor(BxR.val, &BxR);
        if (GuiButton(BxR.rect, BxR.label)) {
            BxR.val += 0.2;

            if ( BxR.val > 1) {
                BxR.val = -1;
            }
        }

        DetermineButtonColor(RxY.val, &RxY);
        if (GuiButton(RxY.rect, RxY.label)) {
            RxY.val += 0.2;

            if ( RxY.val > 1) {
                RxY.val = -1;
            }
        }

        DetermineButtonColor(RxG.val, &RxG);
        if (GuiButton(RxG.rect, RxG.label)) {
            RxG.val += 0.2;

            if ( RxG.val > 1) {
                RxG.val = -1;
            }
        }

        DetermineButtonColor(RxB.val, &RxB);
        if (GuiButton(RxB.rect, RxB.label)) {
            RxB.val += 0.2;

            if ( RxB.val > 1) {
                RxB.val = -1;
            }
        }

        DetermineButtonColor(RxR.val, &RxR);
        if (GuiButton(RxR.rect, RxR.label)) {
            RxR.val += 0.2;

            if ( RxR.val > 1) {
                RxR.val = -1;
            }
        }

        GuiLoadStyleDefault();
        GuiSetStyle(DEFAULT, TEXT_SIZE, 20);
        GuiLabel(PresetsLabel.rect, "Presets");
        if (GuiButton(SnakePresetButton.rect, "Worms")) {
            YxY.val = 1;
            YxG.val = 0.2;
            YxB.val = 0;
            YxR.val = 0;

            GxY.val = 0;
            GxG.val = 1;
            GxB.val = 0.2;
            GxR.val = 0;

            BxY.val = 0;
            BxG.val = 0;
            BxB.val = 1;
            BxR.val = 0.2;

            RxY.val = 0;
            RxG.val = 0;
            RxB.val = 0;
            RxR.val = 1;

            MinAttractionSlider.value = 60;
            MaxAttractionSlider.value = 400;
            GravitySlider.value = 100;
            QuarkSlider.value = 1000;
        }

        if (GuiButton(AtomPresetButton.rect, "Cells")) {
            YxY.val = 0;
            YxG.val = 0;
            YxB.val = 0;
            YxR.val = 0;

            GxY.val = 0.2;
            GxG.val = 1;
            GxB.val = -0.4;
            GxR.val = 0;

            BxY.val = 0;
            BxG.val = 0.8;
            BxB.val = 0;
            BxR.val = -0.6;

            RxY.val = 0;
            RxG.val = 0.6;
            RxB.val = 0;
            RxR.val = -0.2;

            MinAttractionSlider.value = 100;
            MaxAttractionSlider.value = 400;
            GravitySlider.value = 100;
            QuarkSlider.value = 1000;
        }

        if (GuiButton(Preset3Button.rect, "TBA")) {
            
        }

        GuiLabel(FunctionsLabel.rect, "Functions");

        if (GuiButton(ClearButton.rect, "CLEAR")) {
            QUARK_COUNT = 0;
            CLEARED = 1;
        }

        if (GuiButton(ResetButton.rect, "RESET")) {
            YxY.val = 0;
            YxG.val = 0;
            YxB.val = 0;
            YxR.val = 0;
            GxY.val = 0;
            GxG.val = 0;
            GxB.val = 0;
            GxR.val = 0;
            BxY.val = 0;
            BxG.val = 0;
            BxB.val = 0;
            BxR.val = 0;
            RxY.val = 0;
            RxG.val = 0;
            RxB.val = 0;
            RxR.val = 0;

            MinAttractionSlider.value = 100;
            MaxAttractionSlider.value = 500;
            GravitySlider.value = 100;
            QuarkSlider.value = 1000;
        }

        if (GuiButton(GenerateButton.rect, "GENERATE")) {
            CLEARED = 0;
            UpdateSettings();
            GENERATE = 1;
        }
    }

    return;
}

void UpdateSettings() {
    if (!CLEARED) {
        QUARK_COUNT = QuarkSlider.value;
        GRAVITY = GravitySlider.value;
    }

    MIN_ATTRACTION_DISTANCE = MinAttractionSlider.value;
    MAX_ATTRACTION_DISTANCE = MaxAttractionSlider.value;

    INTERACTION_MATRIX[0][0] = YxY.val;
    INTERACTION_MATRIX[0][1] = YxG.val;
    INTERACTION_MATRIX[0][2] = YxB.val;
    INTERACTION_MATRIX[0][3] = YxR.val;

    INTERACTION_MATRIX[1][0] = GxY.val;
    INTERACTION_MATRIX[1][1] = GxG.val;
    INTERACTION_MATRIX[1][2] = GxB.val;
    INTERACTION_MATRIX[1][3] = GxR.val;

    INTERACTION_MATRIX[2][0] = BxY.val;
    INTERACTION_MATRIX[2][1] = BxG.val;
    INTERACTION_MATRIX[2][2] = BxB.val;
    INTERACTION_MATRIX[2][3] = BxR.val;

    INTERACTION_MATRIX[3][0] = RxY.val;
    INTERACTION_MATRIX[3][1] = RxG.val;
    INTERACTION_MATRIX[3][2] = RxB.val;
    INTERACTION_MATRIX[3][3] = RxR.val;

    return;
}