#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"

class LaunchFrame : public Frame {
private:
    const float buttonWidth = 200.0f;  // 按钮的宽度
    const float buttonHeight = 50.0f;  // 按钮的高度
    const float buttonSpacing = 20.0f;  // 按钮之间的间距
    Rectangle buttons[2];  // 存储2个按钮的位置和尺寸
    const char* buttonLabels[2];  // 按钮的标签文本

    // 启动动画相关变量
    float animationDuration = 3.0f;  // 动画持续时间
    float elapsedTime = 0.0f;  // 已经过的时间
    bool animationFinished = false;  // 动画是否结束

public:
    LaunchFrame();  // 构造函数
    void init() override;  // 初始化函数
    void draw() override;  // 绘制函数
};
