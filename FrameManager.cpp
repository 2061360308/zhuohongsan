#include <iostream>
#include "raylib.h"
#include <unordered_map>
#include "Frame.h"
#include "FrameManager.h"

FrameManager::FrameManager() {
    // 构造函数实现
}

void FrameManager::addFrame(Frame* frame) {
    frames[frame->name] = frame;
}

void FrameManager::setFrame(std::string name) {
    this->state = name;
}

void FrameManager::draw() {
    Frame* currentFrame = frames[state];

    if (currentFrame != nullptr) {
        if (!currentFrame->has_init) {
            currentFrame->init();
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        currentFrame->draw();
        EndDrawing();
    }
}

FrameManager frameManager;