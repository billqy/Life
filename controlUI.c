#include "controlUI.h"

#include "settings.h"

int RULES_TOGGLE = 0;

Button RulesButton;
Panel BackgroundPanel;

Label QuarkLabel;
Slider QuarkSlider;
Label GravityLabel;
Slider GravitySlider;

void InitUI() {
    GuiSetAlpha(0.7);
    int STD_LABEL_W = 200;
    int STD_LABEL_H = 15;
    float STD_PAD = 35;

    Rectangle RulesRect = {20, sHeight/2 - 50, 50, 100};
    Rectangle BackgroundPanelRect = {75, 75, 300, sHeight - 150};

    RulesButton.rect = RulesRect;
    BackgroundPanel.rect = BackgroundPanelRect;

    QuarkLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 40, STD_LABEL_W, STD_LABEL_H};
    QuarkSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 60, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    QuarkSlider.pValue = &(QuarkSlider.value);
    QuarkSlider.value = QUARK_COUNT;
    QuarkSlider.minVal = 50;
    QuarkSlider.maxVal = 2000;

    GravityLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 100, STD_LABEL_W, STD_LABEL_H};
    GravitySlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 120, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    GravitySlider.pValue = &(GravitySlider.value);
    GravitySlider.value = GRAVITY;
    GravitySlider.minVal = 50;
    GravitySlider.maxVal = 200;

    // TO ADD (IN ORDER OF UI APPEARANCE)
    // INTERACTION MATRIX
    // RED %
    // GREEN %
    // BLUE %
    // YELLOW %
    // PRESETS
    // CLEAR
    // GENERATE
    // RESET TO DEFAULT

    return;
}

void DrawControlUI() {
    GuiLoadStyleDefault();

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
    }

    return;
}

void UpdateSettings() {
    QUARK_COUNT = QuarkSlider.value;
    GRAVITY = GravitySlider.value;

    return;
}