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
        DrawRectangleLines(static_cast<int>(cardX), static_cast<int>(startY), static_cast<int>(cardWidth), static_cast<int>(cardHeight), BLACK); // »æÖÆ±ß¿ò
    }
}

void CardContainer::UpdatePosition(float startX, float startY) {
    this->startX = startX;
    this->startY = startY;
}

void CardContainer::SetCardSpacing(float spacing) {
    cardSpacing = spacing;
}
