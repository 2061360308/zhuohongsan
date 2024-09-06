#include "PlayingFrame.h"
#include "global.h"

PlayingFrame::PlayingFrame() {
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
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

void PlayingFrame::draw() {
    Vector2 mousePosition = GetMousePosition();

    if (CheckCollisionPointRec(mousePosition, backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        frameManager.setFrame("MAIN_MENU");
    }

    DrawText("Game Play Screen", screenWidth / 2 - MeasureText("Game Play Screen", 20) / 2, screenHeight / 2 - 10, 20, BLACK);

    if (CheckCollisionPointRec(mousePosition, backButton)) {
        DrawRectangleRec(backButton, DARKGRAY);
    }
    else {
        DrawRectangleRec(backButton, LIGHTGRAY);
    }
    DrawRectangleLinesEx(backButton, 3, BLACK);

    int textWidth = MeasureText(backButtonLabel, 20);
    DrawText(backButtonLabel, backButton.x + (backButton.width - textWidth) / 2, backButton.y + (backButton.height - 20) / 2, 20, BLACK);
}