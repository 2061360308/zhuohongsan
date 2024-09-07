#include "PlayingFrame.h"
#include "global.h"
#include <iostream>

// PlayingFrame 构造函数，设置帧的名称
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // 初始化 CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // 加载背景图片
    backgroundTexture = LoadTexture("images/bg1.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }

    // 加载头像图片
    avatarTexture = LoadTexture("images/head.png");

    // 设置头像的缩放因子
    float scale = 0.2f;

    // 计算左下角头像的位置
    avatarPositionLeft = { 10, screenHeight - (avatarTexture.height * scale) - 10 };

    // 计算右上角头像的位置
    avatarPositionRight = { screenWidth - (avatarTexture.width * scale) - 10, 10 };

    // 计算左上角头像的位置
    avatarPositionTopLeft = { 10, 10 };

    // 计算扑克牌的起始位置
    startX = avatarPositionLeft.x + avatarTexture.width * scale + 45; // 头像右边的距离
    startY = avatarPositionLeft.y + (avatarTexture.height * scale - cardHeight) / 2;

    // 更新 CardContainer 的位置
    cardContainer.UpdatePosition(startX, startY);

    // 计算按钮的起始位置
    buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
    buttonY = startY - buttonHeight - 20.0f;

    // 计算 "Hit" 按钮的x坐标
    buttonX2 = buttonX1 + buttonWidth + buttonSpacing;

    // 计算圆形按钮的位置
    circleButtonX = screenWidth - circleButtonRadius - 20.0f;
    circleButtonY = screenHeight - circleButtonRadius - 20.0f;

    // 添加扑克牌到容器中
    Texture2D cardTexture = LoadTexture("images/card.png"); // 替换为实际的扑克牌图片路径
    for (int i = 0; i < 18; ++i) {
        cardContainer.AddCard(cardTexture);
    }

    has_init = true;
}

void PlayingFrame::draw() {
    DrawTexture(backgroundTexture, 0, 0, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexture, avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

    // 绘制扑克牌
    cardContainer.Draw();

    Vector2 mousePosition = GetMousePosition();

    // 绘制 "Skip" 按钮
    DrawRectangle(buttonX1, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX1, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    int buttonTextWidth = MeasureText("Skip", 20);
    DrawText("Skip", buttonX1 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    // 绘制 "Hit" 按钮
    DrawRectangle(buttonX2, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX2, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    buttonTextWidth = MeasureText("Hit", 20);
    DrawText("Hit", buttonX2 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    // 检查圆形按钮是否被点击
    if (CheckCollisionPointCircle(mousePosition, { circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        frameManager.setFrame("MAIN_MENU");
    }

    // 绘制圆形按钮
    DrawCircleV({ circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius, LIGHTGRAY);
    DrawCircleLines(circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius, circleButtonRadius, BLACK);

    // 绘制圆形按钮上的文本
    int circleButtonTextWidth = MeasureText("Exit", 20);
    DrawText("Exit", circleButtonX + circleButtonRadius - circleButtonTextWidth / 2, circleButtonY + circleButtonRadius - 10, 20, BLACK);
}

PlayingFrame::~PlayingFrame() {
    UnloadTexture(avatarTexture);
    // 在不需要的情况下卸载扑克牌纹理
}
