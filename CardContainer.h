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
