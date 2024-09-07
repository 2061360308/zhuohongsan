#pragma once
#include <string>

//抽象基类，用于定义游戏中不同界面的公共接口。
class Frame {
public:
    virtual void init() = 0;  // 纯虚函数，初始化帧
    virtual void draw() = 0;  // 纯虚函数，绘制帧
    bool has_init = false;    // 标记帧是否已初始化
    std::string name = "";    // 帧的名称
};
