#pragma once
#include <unordered_map>
#include <string>
#include "Frame.h"

//负责管理所有的帧，并根据需要切换和绘制当前帧
class FrameManager {
private:
    std::unordered_map<std::string, Frame*> frames; // 存储所有帧的哈希表
    std::string state = "MAIN_MENU";               // 当前帧的状态

public:
    FrameManager();  // 构造函数

    void addFrame(Frame* frame);  // 添加帧
    void setFrame(std::string name);  // 设置当前帧,就是切换到另一个画面
    void draw();  // 绘制当前帧
};

// 在头文件中声明 frameManager 实例
extern FrameManager frameManager;
