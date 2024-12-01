#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "Object.h"
#include <functional>

class Button : public Object {
public:
    Button(int x1, int y1, int x2, int y2, std::function<void()> onClick);
    void update();
    void draw();

private:
    std::function<void()> onClick;
    bool isHovered;
};

#endif