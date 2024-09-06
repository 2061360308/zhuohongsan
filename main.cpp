// 主窗口
#if 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "raylib.h"
#include <string>
#include <unordered_map>

//------------------------------------------------------------------------------------
// Module Functions Declaration (local)
//------------------------------------------------------------------------------------
// static void InitGame(void);         // Initialize game
// void InitFrame(void);       // Update game (one frame)
// static void DrawGame(void);         // Draw game (one frame)
// static void UnloadGame(void);       // Unload game
// static void InitGame(void);  // Update and Draw (one frame)

#include "Frame.h"
#include "FrameManager.h"
#include "LaunchFrame.h"
#include "PlayingFrame.h"
#include "global.h"

// 主程序
int main()
{
    InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

    // 设置目标帧率
    SetTargetFPS(60);

    // 实例化 LaunchFrame
    LaunchFrame launchFrame;
    PlayingFrame playingFrame;

    // 添加游戏界面
    frameManager.addFrame(&launchFrame);
    frameManager.addFrame(&playingFrame);

    frameManager.setFrame("MAIN_MENU");

    // 主游戏循环
    while (!WindowShouldClose())
    {
        // 更新和绘制游戏界面
        frameManager.draw();
    }

    // 关闭窗口和相关资源
    CloseWindow();

    return 0;
}

#endif

// 扑克牌
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