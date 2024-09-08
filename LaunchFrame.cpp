#include "LaunchFrame.h"
#include "global.h"

// LaunchFrame 构造函数，设置帧的名称
LaunchFrame::LaunchFrame() {
    this->name = "MAIN_MENU";  // 将帧的名称设置为 "MAIN_MENU"
}

// 初始化函数，设置按钮标签
void LaunchFrame::init() {
    // 设置每个按钮的标签
    buttonLabels[0] = "Create Room";
    buttonLabels[1] = "Join Room";

    // 标记帧已初始化
    has_init = true;
}

// 绘制函数，绘制按钮并处理点击事件
void LaunchFrame::draw() {
    // 获取当前窗口尺寸
    screenWidth = GetScreenWidth();
    screenHeight = GetScreenHeight();

    // 获取当前鼠标的位置
    Vector2 mousePosition = GetMousePosition();

    // 计算已经过的时间
    elapsedTime += GetFrameTime();

    if (elapsedTime < animationDuration) {
        // 启动动画逻辑
        ClearBackground(RAYWHITE);
        DrawText("ZhuoHongSan", screenWidth / 2 - MeasureText("ZhuoHongSan", 40) / 2, screenHeight / 2 - 20, 40, RED);
        // 你可以在这里添加更多与扑克牌相关的元素
        // 例如，绘制扑克牌图像，进行简单动画等
    }
    else {
        animationFinished = true;
    }

    if (animationFinished) {
        // 计算按钮的初始位置
        const float startX = screenWidth / 2.0f - buttonWidth / 2.0f;
        const float startY = screenHeight / 2.0f - (buttonHeight * 0.5f) - buttonSpacing;

        // 设置每个按钮的位置和尺寸
        buttons[0] = { startX, startY, buttonWidth, buttonHeight };
        buttons[1] = { startX, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight };

        // 检查每个按钮是否被点击，如果是则切换到 "GAME_PLAY" 帧
        for (int i = 0; i < 2; i++) {
            if (CheckCollisionPointRec(mousePosition, buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                frameManager.setFrame("GAME_PLAY");
            }
        }

        // 绘制每个按钮
        for (int i = 0; i < 2; i++) {
            // 如果鼠标悬停在按钮上，改变按钮颜色
            if (CheckCollisionPointRec(mousePosition, buttons[i])) {
                DrawRectangleRec(buttons[i], DARKGRAY);
            }
            else {
                DrawRectangleRec(buttons[i], LIGHTGRAY);
            }
            // 绘制按钮边框
            DrawRectangleLinesEx(buttons[i], 3, BLACK);

            // 计算文本的宽度并绘制文本，使其在按钮中居中
            int textWidth = MeasureText(buttonLabels[i], 20);
            DrawText(buttonLabels[i], buttons[i].x + (buttons[i].width - textWidth) / 2, buttons[i].y + (buttons[i].height - 20) / 2, 20, BLACK);
        }
    }
}
