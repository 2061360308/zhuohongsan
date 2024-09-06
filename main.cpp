//主窗口
#if 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "raylib.h"

// 定义界面状态
enum GameState { MAIN_MENU, GAME_PLAY };

// 主程序
int main() {
    // 初始化窗口
    const int screenWidth = 1980;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

    // 设置目标帧率
    SetTargetFPS(60);

    // 定义按钮位置和尺寸
    const int buttonWidth = 200;
    const int buttonHeight = 50;
    const int buttonSpacing = 20;
    const int startX = screenWidth / 2 - buttonWidth / 2;
    const int startY = screenHeight / 2 - (buttonHeight * 1.5) - (buttonSpacing * 2);

    Rectangle buttons[3] = {
        { startX, startY, buttonWidth, buttonHeight },
        { startX, startY + buttonHeight + buttonSpacing, buttonWidth, buttonHeight },
        { startX, startY + 2 * (buttonHeight + buttonSpacing), buttonWidth, buttonHeight }
    };

    const char* buttonLabels[3] = { "3 Players", "4 Players", "5 Players" };

    // 定义返回主菜单按钮位置和尺寸（左上角）
    Rectangle backButton = { 20, 20, buttonWidth, buttonHeight }; // 左上角位置
    const char* backButtonLabel = "Back to Menu";

    // 当前游戏状态
    GameState state = MAIN_MENU;

    // 主游戏循环
    while (!WindowShouldClose()) {
        // 更新
        Vector2 mousePosition = GetMousePosition();

        if (state == MAIN_MENU) {
            for (int i = 0; i < 3; i++) {
                if (CheckCollisionPointRec(mousePosition, buttons[i]) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                    // 点击按钮后进入游戏对局界面
                    state = GAME_PLAY;
                }
            }
        }
        else if (state == GAME_PLAY) {
            if (CheckCollisionPointRec(mousePosition, backButton) && IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
                // 点击返回按钮返回主菜单
                state = MAIN_MENU;
            }
        }

        // 绘制
        BeginDrawing();
        ClearBackground(RAYWHITE);

        if (state == MAIN_MENU) {
            // 绘制主菜单界面
            for (int i = 0; i < 3; i++) {
                if (CheckCollisionPointRec(mousePosition, buttons[i])) {
                    DrawRectangleRec(buttons[i], DARKGRAY); // 鼠标悬停时的颜色
                }
                else {
                    DrawRectangleRec(buttons[i], LIGHTGRAY); // 鼠标未悬停时的颜色
                }
                DrawRectangleLinesEx(buttons[i], 3, BLACK); // 按钮边框

                // 绘制按钮文本
                int textWidth = MeasureText(buttonLabels[i], 20);
                DrawText(buttonLabels[i], buttons[i].x + (buttons[i].width - textWidth) / 2, buttons[i].y + (buttons[i].height - 20) / 2, 20, BLACK);
            }
        }
        else if (state == GAME_PLAY) {
            // 绘制游戏对局界面
            DrawText("Game Play Screen", screenWidth / 2 - MeasureText("Game Play Screen", 20) / 2, screenHeight / 2 - 10, 20, BLACK);

            // 绘制返回主菜单按钮
            if (CheckCollisionPointRec(mousePosition, backButton)) {
                DrawRectangleRec(backButton, DARKGRAY); // 鼠标悬停时的颜色
            }
            else {
                DrawRectangleRec(backButton, LIGHTGRAY); // 鼠标未悬停时的颜色
            }
            DrawRectangleLinesEx(backButton, 3, BLACK); // 按钮边框

            // 绘制按钮文本
            int textWidth = MeasureText(backButtonLabel, 20);
            DrawText(backButtonLabel, backButton.x + (backButton.width - textWidth) / 2, backButton.y + (backButton.height - 20) / 2, 20, BLACK);
        }

        EndDrawing();
    }

    // 关闭窗口和相关资源
    CloseWindow();

    return 0;
}


#endif 

//扑克牌
#if 0
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
#include <algorithm>
#include "raylib.h"

// 定义扑克牌结构体
struct Card {
    enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES, NONE } suit;
    int rank; // 1-13 for A-K
    bool isSpecial; // 标记特殊牌（红桃3和方块3）
};

// 打印扑克牌
void DrawCard(const Card& card, int x, int y) {
    const char* suits[] = { "Hearts", "Diamonds", "Clubs", "Spades" };
    const char* ranks[] = { "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };

    DrawRectangle(x, y, 60, 90, WHITE);
    DrawRectangleLines(x, y, 60, 90, BLACK);
    DrawText(ranks[card.rank - 1], x + 5, y + 5, 20, BLACK);
    DrawText(suits[card.suit], x + 5, y + 30, 20, BLACK);

    if (card.isSpecial) {
        DrawText("Special", x + 5, y + 60, 20, RED);
    }
}

int main() {
    // 初始化窗口
    const int screenWidth = 1980;
    const int screenHeight = 1080;
    InitWindow(screenWidth, screenHeight, "Card Game Example");

    SetTargetFPS(60);

    // 创建扑克牌
    std::vector<Card> deck;
    for (int s = 0; s < 4; ++s) {
        for (int r = 1; r <= 13; ++r) {
            Card card;
            card.suit = static_cast<Card::Suit>(s);
            card.rank = r;
            card.isSpecial = (s == Card::HEARTS && r == 3) || (s == Card::DIAMONDS && r == 3);
            deck.push_back(card);
        }
    }
    // 添加鬼牌
    deck.push_back({ Card::NONE, 0, false }); // Jokers
    deck.push_back({ Card::NONE, 0, false });

    // 洗牌
    std::random_shuffle(deck.begin(), deck.end());

    // 发牌
    std::vector<std::vector<Card>> hands(5);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 11; ++j) {
            hands[i].push_back(deck.back());
            deck.pop_back();
        }
    }
    hands[4].resize(10);
    for (int j = 0; j < 10; ++j) {
        hands[4][j] = deck.back();
        deck.pop_back();
    }

    // 主游戏循环
    while (!WindowShouldClose()) {
        // 更新
        Vector2 mousePosition = GetMousePosition();

        // 绘制
        BeginDrawing();
        ClearBackground(RAYWHITE);

        // 绘制玩家手牌
        int offsetX = 20;
        int offsetY = 20;
        for (int i = 0; i < 5; ++i) {
            for (size_t j = 0; j < hands[i].size(); ++j) {
                DrawCard(hands[i][j], offsetX + j * 70, offsetY + i * 100);
            }
        }

        EndDrawing();
    }

    // 关闭窗口和相关资源
    CloseWindow();

    return 0;
}
#endif 