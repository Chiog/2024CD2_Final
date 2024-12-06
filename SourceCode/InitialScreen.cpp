#include "InitialScreen.h"
#include "data/DataCenter.h"
#include <allegro5/allegro_primitives.h>
#include "Game.h"


#include "buttons/ButtonInitStart.h"    // 加入這兩行
#include "buttons/ButtonInitQuit.h"
void InitialScreen::init() {
    // 創建開始遊戲按鈕
    Button* startButton = new ButtonInitStart(
        300, 200,     // x1, y1 (開始按鈕)
        500, 250      // x2, y2
    );
    
    // 創建退出遊戲按鈕
    Button* quitButton = new ButtonInitQuit(
        300, 300,     // x1, y1 (退出按鈕)
        500, 350      // x2, y2
    );
    
    buttons.push_back(startButton);
    buttons.push_back(quitButton);
}

void InitialScreen::update() {
    // 更新介面元素
    for(auto button : buttons) {
        button->update();
    }
    
}

void InitialScreen::draw() {
    //DataCenter *DC = DataCenter::get_instance();
    
    // 繪製白色背景
    al_clear_to_color(al_map_rgb(255, 255, 255));
    
    // 繪製介面元素
    
    for(auto button : buttons) {
        button->draw();
    }
}

void InitialScreen::clearButtons() {
    for(auto button : buttons) {
        delete button;
    }
    buttons.clear();
}