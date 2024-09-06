#include "LaunchFrame.h"
#include "global.h"

LaunchFrame::LaunchFrame() {
    this->name = "MAIN_MENU";
}

void LaunchFrame::init() {
    const float startX = screenWidth / 2.0f - buttonWidth / 2.0f;
    const float startY = screenHeight / 2.0f - (buttonHeight * 1.5f) - (buttonSpacing * 2.0f);
    buttons[0] = { startX, startY, buttonWidth, buttonHeight };
    buttons[1] = { startX, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };
    buttons[2] = { startX, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight };

    buttonLabels[0] = "3 Players";
    buttonLabels[1] = "4 Players";
    buttonLabels[2] = "5 Players";

    backButton = { 20, 20, buttonWidth, buttonHeight };
    backButtonLabel = "Back to Menu";
    has_init = true;
}

void LaunchFrame::draw() {
    Vector2 mousePosition = GetMousePosition();

    for (int i = 0; i < 3; i++) {
        if (CheckCollisionPointRec(mousePosition, buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            frameManager.setFrame("GAME_PLAY");
        }
    }

    for (int i = 0; i < 3; i++) {
        if (CheckCollisionPointRec(mousePosition, buttons[i])) {
            DrawRectangleRec(buttons[i], DARKGRAY);
        }
        else {
            DrawRectangleRec(buttons[i], LIGHTGRAY);
        }
        DrawRectangleLinesEx(buttons[i], 3, BLACK);

        int textWidth = MeasureText(buttonLabels[i], 20);
        DrawText(buttonLabels[i], buttons[i].x + (buttons[i].width - textWidth) / 2, buttons[i].y + (buttons[i].height - 20) / 2, 20, BLACK);
    }
}