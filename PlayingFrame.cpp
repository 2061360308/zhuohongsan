#if 0
#include "PlayingFrame.h"
#include "global.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

// PlayingFrame 构造函数，设置帧的名称
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // 初始化 CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // 获取初始窗口尺寸
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // 加载背景图片
    backgroundTexture = LoadTexture("images/bg5.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }

    // 加载头像图片
    std::vector<std::string> avatarPaths = { "images/MR.png", "images/ZZ.png", "images/XY.png" };
    std::vector<Texture2D> avatarTextures;
    for (const auto& path : avatarPaths) {
        Texture2D texture = LoadTexture(path.c_str());
        if (texture.id == 0) {
            std::cerr << "Failed to load avatar texture from " << path << std::endl;
        }
        avatarTextures.push_back(texture);
    }

    // 随机打乱头像顺序
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(avatarTextures.begin(), avatarTextures.end(), g);

    // 设置头像的缩放因子
    float scale = 0.2f;

    // 计算头像位置
    avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
    avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
    avatarPositionTopLeft = { 10, 10 };

    // 计算扑克牌的起始位置
    startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45; // 头像右边的距离
    startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

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

    // 保存随机排序后的头像纹理
    avatarTexturesRandomized = avatarTextures;

    has_init = true;
}


void PlayingFrame::draw() {
    // 获取窗口的实际尺寸
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // 绘制背景
    DrawTexture(backgroundTexture, 0, 0, WHITE);

    // 绘制头像
    DrawTextureEx(avatarTexturesRandomized[0], avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[1], avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[2], avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

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
    for (const auto& texture : avatarTexturesRandomized) {
        UnloadTexture(texture);
    }
    // 在不需要的情况下卸载扑克牌纹理
}

#endif 

//修改后
#if 1
#include "PlayingFrame.h"
#include "global.h"
#include <iostream>
#include <algorithm>
#include <random>
#include <vector>

// PlayingFrame 构造函数，设置帧的名称
// PlayingFrame.cpp
PlayingFrame::PlayingFrame()
    : cardContainer(0, 0, cardWidth, cardHeight, cardSpacing) { // 初始化 CardContainer
    this->name = "GAME_PLAY";
}

void PlayingFrame::init() {
    // 获取初始窗口尺寸
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // 加载背景图片
    backgroundTexture = LoadTexture("images/bg4.png");
    if (backgroundTexture.id == 0) {
        std::cerr << "Failed to load background texture!" << std::endl;
    }


    // 加载头像图片
    std::vector<std::string> avatarPaths = { "images/MR.png", "images/ZZ.png", "images/XY.png" };
    avatarTextures.clear(); // 清空之前的纹理

    for (const auto& path : avatarPaths) {
        Texture2D texture = LoadTexture(path.c_str());
        if (texture.id == 0) {
            std::cerr << "Failed to load avatar texture from " << path << std::endl;
        }
        else {
            avatarTextures.push_back(texture);
        }
    }

    // 确保 avatarTextures 至少有两个元素
    if (avatarTextures.size() < 2) {
        std::cerr << "Not enough avatar textures loaded!" << std::endl;
        return; // 不继续执行下面的代码
    }

    // 头像位置
    avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
    avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
    avatarPositionTopLeft = { 10, 10 };

    // 扑克牌的起始位置
    startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45;
    startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

    // 更新 CardContainer 的位置
    cardContainer.UpdatePosition(startX, startY);

    // 按钮的起始位置
    buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
    buttonY = startY - buttonHeight - 20.0f;
    buttonX2 = buttonX1 + buttonWidth + buttonSpacing;
    circleButtonX = screenWidth - circleButtonRadius - 20.0f;
    circleButtonY = screenHeight - circleButtonRadius - 20.0f;

    // 加载扑克牌图像
    Texture2D cardTexture = LoadTexture("images/card.png");
    for (int i = 0; i < 18; ++i) {
        cardContainer.AddCard(cardTexture);
    }

    avatarTexturesRandomized = avatarTextures;

    has_init = true;
}

void PlayingFrame::draw() {
    // 获取窗口的实际尺寸
    int currentScreenWidth = GetScreenWidth();
    int currentScreenHeight = GetScreenHeight();

    // 如果窗口尺寸变化，更新元素位置
    if (currentScreenWidth != screenWidth || currentScreenHeight != screenHeight) {
        screenWidth = currentScreenWidth;
        screenHeight = currentScreenHeight;

        // 重新计算元素的位置
        avatarPositionLeft = { 10, screenHeight - (avatarTextures[0].height * scale) - 10 };
        avatarPositionRight = { screenWidth - (avatarTextures[1].width * scale) - 10, 10 };
        avatarPositionTopLeft = { 10, 10 };

        startX = avatarPositionLeft.x + avatarTextures[0].width * scale + 45;
        startY = avatarPositionLeft.y + (avatarTextures[0].height * scale - cardHeight) / 2;

        cardContainer.UpdatePosition(startX, startY);

        buttonX1 = screenWidth / 2.0f - (buttonWidth + buttonSpacing) / 2.0f;
        buttonY = startY - buttonHeight - 20.0f;
        buttonX2 = buttonX1 + buttonWidth + buttonSpacing;
        circleButtonX = screenWidth - circleButtonRadius - 20.0f;
        circleButtonY = screenHeight - circleButtonRadius - 20.0f;
    }

    // 计算背景图片的缩放比例
    float scaleX = (float)screenWidth / backgroundTexture.width;
    float scaleY = (float)screenHeight / backgroundTexture.height;
    float scale = std::max(scaleX, scaleY); // 选择一个适应宽度或高度的比例

    // 绘制背景
    DrawTextureEx(backgroundTexture, { 0, 0 }, 0.0f, scale, WHITE);

    // 绘制头像
    DrawTextureEx(avatarTexturesRandomized[0], avatarPositionLeft, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[1], avatarPositionRight, 0.0f, 0.2f, WHITE);
    DrawTextureEx(avatarTexturesRandomized[2], avatarPositionTopLeft, 0.0f, 0.2f, WHITE);

    // 绘制扑克牌
    cardContainer.Draw();

    Vector2 mousePosition = GetMousePosition();

    // 绘制按钮和圆形按钮
    DrawRectangle(buttonX1, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX1, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    int buttonTextWidth = MeasureText("Skip", 20);
    DrawText("Skip", buttonX1 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    DrawRectangle(buttonX2, buttonY, buttonWidth, buttonHeight, LIGHTGRAY);
    DrawRectangleLinesEx({ buttonX2, buttonY, buttonWidth, buttonHeight }, 2, BLACK);
    buttonTextWidth = MeasureText("Hit", 20);
    DrawText("Hit", buttonX2 + (buttonWidth - buttonTextWidth) / 2, buttonY + (buttonHeight - 20) / 2, 20, BLACK);

    if (CheckCollisionPointCircle(mousePosition, { circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        frameManager.setFrame("MAIN_MENU");
    }

    DrawCircleV({ circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius }, circleButtonRadius, LIGHTGRAY);
    DrawCircleLines(circleButtonX + circleButtonRadius, circleButtonY + circleButtonRadius, circleButtonRadius, BLACK);

    int circleButtonTextWidth = MeasureText("Exit", 20);
    DrawText("Exit", circleButtonX + circleButtonRadius - circleButtonTextWidth / 2, circleButtonY + circleButtonRadius - 10, 20, BLACK);
}



PlayingFrame::~PlayingFrame() {
    for (const auto& texture : avatarTexturesRandomized) {
        UnloadTexture(texture);
    }
    // 在不需要的情况下卸载扑克牌纹理
}

#endif 