#include <iostream>
#include "raylib.h"
#include <unordered_map>
#include "Frame.h"
#include "FrameManager.h"

// FrameManager 构造函数
FrameManager::FrameManager() {
    // 构造函数可以进行一些初始化操作，但这里没有特定的初始化逻辑
}

// 添加帧到 FrameManager
void FrameManager::addFrame(Frame* frame) {
    // 使用帧的名称作为键，将帧对象存储到 frames 哈希表中
    frames[frame->name] = frame;
}

// 设置当前显示的帧
void FrameManager::setFrame(std::string name) {
    // 设置当前帧的状态
    this->state = name;
}

// 绘制当前帧
void FrameManager::draw() {
    // 根据当前状态获取对应的帧对象
    Frame* currentFrame = frames[state];

    if (currentFrame != nullptr) {  // 确保帧对象存在
        if (!currentFrame->has_init) {  // 如果帧尚未初始化
            currentFrame->init();  // 初始化帧
            currentFrame->has_init = true;  // 标记帧已初始化
        }

        // 开始绘制
        BeginDrawing();
        ClearBackground(RAYWHITE);  // 清空背景为白色
        currentFrame->draw();  // 绘制当前帧的内容
        EndDrawing();
    }
}

// 全局 FrameManager 对象实例
FrameManager frameManager;
