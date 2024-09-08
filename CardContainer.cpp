#if 0
// CardContainer.cpp
#include "CardContainer.h"

CardContainer::CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing)
    : startX(startX), startY(startY), cardWidth(cardWidth), cardHeight(cardHeight), cardSpacing(cardSpacing) {}

void CardContainer::AddCard(Texture2D cardTexture) {
    cards.push_back(cardTexture);
}

void CardContainer::Draw() {
    for (size_t i = 0; i < cards.size(); ++i) {
        float cardX = startX + i * (cardWidth + cardSpacing);
        DrawTexture(cards[i], static_cast<int>(cardX), static_cast<int>(startY), WHITE);
        DrawRectangleLines(static_cast<int>(cardX), static_cast<int>(startY), static_cast<int>(cardWidth), static_cast<int>(cardHeight), BLACK); // 绘制边框
    }
}

void CardContainer::UpdatePosition(float startX, float startY) {
    this->startX = startX;
    this->startY = startY;
}

void CardContainer::SetCardSpacing(float spacing) {
    cardSpacing = spacing;
}
#endif 

#if 1
#include "CardContainer.h"

CardContainer::CardContainer(float startX, float startY, float cardWidth, float cardHeight, float cardSpacing)
    : startX(startX), startY(startY), cardWidth(cardWidth), cardHeight(cardHeight), cardSpacing(cardSpacing) {}

void CardContainer::AddCard(Texture2D cardTexture) {
    cards.push_back(cardTexture);
}

void CardContainer::Draw() {
    UpdateCardPositions(); // 确保位置在绘制时是最新的
    for (size_t i = 0; i < cards.size(); ++i) {
        float cardX = startX + i * (cardWidth + cardSpacing);
        DrawTexture(cards[i], static_cast<int>(cardX), static_cast<int>(startY), WHITE);
        DrawRectangleLines(static_cast<int>(cardX), static_cast<int>(startY), static_cast<int>(cardWidth), static_cast<int>(cardHeight), BLACK); // 绘制边框
    }
}

void CardContainer::UpdatePosition(float startX, float startY) {
    this->startX = startX;
    this->startY = startY;
    UpdateCardPositions(); // 更新扑克牌的位置
}

void CardContainer::SetCardSpacing(float spacing) {
    cardSpacing = spacing;
}

void CardContainer::SetCardSize(float width, float height) {
    cardWidth = width;
    cardHeight = height;
}

void CardContainer::UpdateCardPositions() {
    // 可以在这里实现更复杂的位置调整逻辑，例如处理窗口大小变化
}

#endif 
