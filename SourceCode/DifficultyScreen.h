
#ifndef DIFFICULTY_SCREEN_H
#define DIFFICULTY_SCREEN_H

#include "Object.h"
#include "buttons/Button.h"
#include <vector>

class DifficultyScreen {
public:
    DifficultyScreen() {}
    void init();
    void update();
    void draw();
    
private:
    std::vector<Button*> buttons;  // 如果需要在初始介面上放置按鈕
};

#endif