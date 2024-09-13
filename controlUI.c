#include "controlUI.h"

#include "settings.h"

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

    Rectangle RulesRect = {20, sHeight/2 - 50, 50, 100};
    Rectangle BackgroundPanelRect = {75, 75, 300, sHeight - 150};

    RulesButton.rect = RulesRect;
    BackgroundPanel.rect = BackgroundPanelRect;

    // Quarks
    QuarkLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 40, STD_LABEL_W, STD_LABEL_H};
    QuarkSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 60, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    QuarkSlider.pValue = &(QuarkSlider.value);
    QuarkSlider.value = QUARK_COUNT;
    QuarkSlider.minVal = 50;
    QuarkSlider.maxVal = 2000;

    // Gravity
    GravityLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 100, STD_LABEL_W, STD_LABEL_H};
    GravitySlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 120, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    GravitySlider.pValue = &(GravitySlider.value);
    GravitySlider.value = GRAVITY;
    GravitySlider.minVal = 50;
    GravitySlider.maxVal = 200;

    // Ratios
    RedPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 160, STD_LABEL_W, STD_LABEL_H};
    RedPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 180, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    RedPercentSlider.pValue = &(RedPercentSlider.value);
    RedPercentSlider.value = 25;
    RedPercentSlider.minVal = 0;
    RedPercentSlider.maxVal = 100;

    YellowPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 220, STD_LABEL_W, STD_LABEL_H};
    YellowPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 240, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    YellowPercentSlider.pValue = &(YellowPercentSlider.value);
    YellowPercentSlider.value = 25;
    YellowPercentSlider.minVal = 0;
    YellowPercentSlider.maxVal = 100;

    GreenPercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 280, STD_LABEL_W, STD_LABEL_H};
    GreenPercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 300, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    GreenPercentSlider.pValue = &(GreenPercentSlider.value);
    GreenPercentSlider.value = 25;
    GreenPercentSlider.minVal = 0;
    GreenPercentSlider.maxVal = 100;

    BluePercentLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 340, STD_LABEL_W, STD_LABEL_H};
    BluePercentSlider.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD, BackgroundPanelRect.y + 360, BackgroundPanelRect.width - 2.5*STD_PAD, STD_LABEL_H};
    BluePercentSlider.pValue = &(BluePercentSlider.value);
    BluePercentSlider.value = 25;
    BluePercentSlider.minVal = 0;
    BluePercentSlider.maxVal = 100;

    // Interaction Matrix

    // Presets
    PresetsLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + 640, STD_LABEL_W, STD_LABEL_H};
    SnakePresetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD - 20, BackgroundPanelRect.y + 660, 80, 40};
    AtomPresetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 70, BackgroundPanelRect.y + 660, 80, 40};
    Preset3Button.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 160, BackgroundPanelRect.y + 660, 80, 40};

    // Functions (Clear, Reset, Generate)
    FunctionsLabel.rect = (Rectangle) {BackgroundPanelRect.x + BackgroundPanelRect.width/2 - STD_PAD, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 80, STD_LABEL_W, STD_LABEL_H};
    ClearButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD - 20, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 60, 120, 40};
    ResetButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 120, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 60, 120, 40};
    GenerateButton.rect = (Rectangle) {BackgroundPanelRect.x + STD_PAD + 20, BackgroundPanelRect.y + BackgroundPanelRect.height - STD_PAD - 15, 200, 40};


    

    // FUNCTIONALITY TO ADD (IN ORDER OF UI APPEARANCE)
    // INTERACTION MATRIX
    // RED %
    // GREEN %
    // BLUE %
    // YELLOW %
    // PRESETS
    // CLEAR
    // GENERATE
    // RESET (TO DEFAULT)

    // MOUSE1 ATTRACTION
    // MOUSE2 REPULSION

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

        GuiLabel(RedPercentLabel.rect, "Red %");
        GuiSlider(RedPercentSlider.rect, "0", "100", RedPercentSlider.pValue, RedPercentSlider.minVal, RedPercentSlider.maxVal);

        GuiLabel(YellowPercentLabel.rect, "Yellow %");
        GuiSlider(YellowPercentSlider.rect, "0", "100", YellowPercentSlider.pValue, YellowPercentSlider.minVal, YellowPercentSlider.maxVal);

        GuiLabel(GreenPercentLabel.rect, "Green %");
        GuiSlider(GreenPercentSlider.rect, "0", "100", GreenPercentSlider.pValue, GreenPercentSlider.minVal, GreenPercentSlider.maxVal);

        GuiLabel(BluePercentLabel.rect, "Blue %");
        GuiSlider(BluePercentSlider.rect, "0", "100", BluePercentSlider.pValue, BluePercentSlider.minVal, BluePercentSlider.maxVal);

        GuiLabel(PresetsLabel.rect, "Presets");
        if (GuiButton(SnakePresetButton.rect, "Snake")) {
            
        }

        if (GuiButton(AtomPresetButton.rect, "Atom")) {
            
        }

        if (GuiButton(Preset3Button.rect, "Preset")) {
            
        }

        GuiLabel(FunctionsLabel.rect, "Functions");

        if (GuiButton(ClearButton.rect, "CLEAR")) {
            
        }

        if (GuiButton(ResetButton.rect, "RESET")) {
            
        }

        if (GuiButton(GenerateButton.rect, "GENERATE")) {
            
        }
    }

    return;
}

void UpdateSettings() {
    QUARK_COUNT = QuarkSlider.value;
    GRAVITY = GravitySlider.value;

    return;
}