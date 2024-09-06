#pragma once
#include <string>

class Frame {
public:
    virtual void init() = 0;
    virtual void draw() = 0;
    bool has_init = false;
    std::string name = "";
};