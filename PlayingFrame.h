#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"

class PlayingFrame : public Frame {
private:
    const float buttonWidth = 200.0f;
    const float buttonHeight = 50.0f;
    const float buttonSpacing = 20.0f;
    Rectangle buttons[3];
    const char* buttonLabels[3];
    Rectangle backButton;
    const char* backButtonLabel;

public:
    PlayingFrame();
    void init() override;
    void draw() override;
};