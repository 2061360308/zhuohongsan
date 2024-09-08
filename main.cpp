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
// 静态函数声明，初始化游戏
// static void InitGame(void);         // Initialize game
// void InitFrame(void);       // Update game (one frame)
// 静态函数声明，绘制游戏画面
// static void DrawGame(void);         // Draw game (one frame)
// 静态函数声明，卸载游戏资源
// static void UnloadGame(void);       // Unload game
// 静态函数声明，初始化游戏，重复声明
// static void InitGame(void);  // Update and Draw (one frame)

// 包含自定义头文件，定义不同的游戏帧和管理器
#include "Frame.h"
#include "FrameManager.h"
#include "LaunchFrame.h"
#include "PlayingFrame.h"
#include "global.h"

// 主程序入口
int main()
{
    // 设置窗口可调整大小
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);

    // 初始化窗口，参数分别为宽度、高度和窗口标题
    InitWindow(screenWidth, screenHeight, "Raylib Menu Example");

    // 设置目标帧率为60帧每秒
    SetTargetFPS(60);

    // 实例化 LaunchFrame 和 PlayingFrame 对象
    LaunchFrame launchFrame;
    PlayingFrame playingFrame;

    // 向 FrameManager 添加游戏界面
    frameManager.addFrame(&launchFrame);
    frameManager.addFrame(&playingFrame);

    // 设置当前显示的界面为 "MAIN_MENU"
    frameManager.setFrame("MAIN_MENU");

    // 主游戏循环，窗口关闭前一直运行
    while (!WindowShouldClose())
    {
        // 更新和绘制当前游戏界面
        frameManager.draw();
    }

    // 关闭窗口并卸载相关资源
    CloseWindow();

    return 0;
}

#endif
