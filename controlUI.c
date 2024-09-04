#include "controlUI.h"

#include "settings.h"

int RULES_TOGGLE = 0;
Button RulesButton;
Panel BackgroundPanel;

void InitUI() {
    GuiSetAlpha(0.2);

    RulesButton.rect = (Rectangle) {20, sHeight/2 - 50, 50, 100};
    BackgroundPanel.rect = (Rectangle) {75, 75, 300, sHeight - 150};

    return;
}

void DrawControlUI() {

    if (GuiButton(RulesButton.rect, "RULES")) {
        if (RULES_TOGGLE) {
            RULES_TOGGLE = 0;
        } else {
            RULES_TOGGLE = 1;
        }
    }

    if (RULES_TOGGLE == 1) {
        GuiPanel(BackgroundPanel.rect, "SIM RULES");
    }

    return;
}