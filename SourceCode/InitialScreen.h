#ifndef INITIALSCREEN_H_INCLUDED
#define INITIALSCREEN_H_INCLUDED

#include "Object.h"
#include "Button.h"
#include <vector>

class InitialScreen {
public:
    InitialScreen() {}
    void init();
    void update();
    void draw();
    
private:
    std::vector<Button*> buttons;  // 如果需要在初始介面上放置按鈕
};

#endif