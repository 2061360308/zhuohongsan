#if 0
#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"
#include "CardContainer.h"

class PlayingFrame : public Frame {
private:
    const float cardWidth = 50.0f;    // 扑克牌宽度
    const float cardHeight = 70.0f;   // 扑克牌高度
    const float cardSpacing = 0.0f;   // 扑克牌之间的间隔

    const float buttonWidth = 80.0f;  // 按钮宽度
    const float buttonHeight = 30.0f; // 按钮高度
    const float buttonSpacing = 20.0f; // 按钮之间的间隔

    const float circleButtonRadius = 30.0f; // 圆形按钮的半径

    // 头像相关变量
    Texture2D avatarTexture;
    Vector2 avatarPositionLeft;
    Vector2 avatarPositionRight;
    Vector2 avatarPositionTopLeft;
    std::vector<Texture2D> avatarTexturesRandomized;

    // 扑克牌位置
    float startX;
    float startY;

    // 按钮位置
    float buttonX1;
    float buttonY;
    float buttonX2;

    // 圆形按钮位置
    float circleButtonX;
    float circleButtonY;

    Texture2D backgroundTexture; // 背景图片纹理

    CardContainer cardContainer; // 添加 CardContainer 实例

 

public:
    PlayingFrame();  // 构造函数
    ~PlayingFrame(); // 析构函数
    void init() override;  // 初始化函数
    void draw() override;  // 绘制函数
};

#endif 

#if 1
#pragma once
#include "Frame.h"
#include "raylib.h"
#include "FrameManager.h"
#include "CardContainer.h"

class PlayingFrame : public Frame {
private:
    const float cardWidth = 50.0f;       // 扑克牌宽度
    const float cardHeight = 70.0f;      // 扑克牌高度
    const float cardSpacing = 0.0f;      // 扑克牌之间的间隔

    const float buttonWidth = 80.0f;     // 按钮宽度
    const float buttonHeight = 30.0f;    // 按钮高度
    const float buttonSpacing = 20.0f;   // 按钮之间的间隔

    const float circleButtonRadius = 30.0f; // 圆形按钮的半径

    const float scale = 0.2f;            // 头像缩放因子

    // 头像相关变量
    std::vector<Texture2D> avatarTextures; // 头像纹理列表
    Vector2 avatarPositionLeft;            // 左侧头像位置
    Vector2 avatarPositionRight;           // 右侧头像位置
    Vector2 avatarPositionTopLeft;         // 左上角头像位置
    std::vector<Texture2D> avatarTexturesRandomized; // 随机排序后的头像纹理

    // 扑克牌位置
    float startX;
    float startY;

    // 按钮位置
    float buttonX1;
    float buttonY;
    float buttonX2;

    // 圆形按钮位置
    float circleButtonX;
    float circleButtonY;

    Texture2D backgroundTexture; // 背景图片纹理

    CardContainer cardContainer; // 扑克牌容器实例

public:
    PlayingFrame();  // 构造函数
    ~PlayingFrame(); // 析构函数

    void init() override;  // 初始化函数
    void draw() override;  // 绘制函数
};


#endif 
