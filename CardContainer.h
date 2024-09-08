#if 0
// CardContainer.h
#ifndef CARD_CONTAINER_H
#define CARD_CONTAINER_H

#include "raylib.h"
#include <vector>

class CardContainer {
public:
    CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing);
    void AddCard(Texture2D cardTexture);
    void Draw();
    void UpdatePosition(float startX, float startY);
    void SetCardSpacing(float spacing);

private:
    std::vector<Texture2D> cards;
    float startX;
    float startY;
    float cardWidth;
    float cardHeight;
    float cardSpacing;
};

#endif // CARD_CONTAINER_H
#endif

#if 1
#ifndef CARD_CONTAINER_H
#define CARD_CONTAINER_H

#include "raylib.h"
#include <vector>

class CardContainer {
public:
    CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing);
    void AddCard(Texture2D cardTexture);
    void Draw();
    void UpdatePosition(float startX, float startY);
    void SetCardSpacing(float spacing);
    void SetCardSize(float width, float height); // 新增：设置扑克牌的尺寸
    void UpdateCardPositions(); // 新增：更新扑克牌的位置

private:
    std::vector<Texture2D> cards;
    float startX;
    float startY;
    float cardWidth;
    float cardHeight;
    float cardSpacing;
};

#endif // CARD_CONTAINER_H

#endif 
