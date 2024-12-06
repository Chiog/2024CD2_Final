#ifndef INITIALSCREEN_H_INCLUDED
#define INITIALSCREEN_H_INCLUDED

#include "Object.h"
#include "buttons/Button.h"
#include <vector>

class InitialScreen {
public:
    /*
    InitialScreen() {}
    ~InitialScreen() {           // 加入解構子
        clearButtons();
    }
    void init();
    void update();
    void draw();*/

     InitialScreen() {}          // 只需要一個建構子
    ~InitialScreen() {          // 加入解構子
        clearButtons();
    }
    void init();
    void update();
    void draw();
    void clearButtons();        // 只宣告，不在這邊做，防止重複define
    
private:
    std::vector<Button*> buttons;  // 如果需要在初始介面上放置按鈕
};

#endif