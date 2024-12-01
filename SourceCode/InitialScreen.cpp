#include "InitialScreen.h"
#include "data/DataCenter.h"
#include <allegro5/allegro_primitives.h>
#include "Game.h"
void InitialScreen::init() {
    //DataCenter *DC = DataCenter::get_instance();
    
    // 創建開始遊戲按鈕
    Button* startButton = new Button(
        300, 250,     // x1, y1 (左上角座標)
        500, 300,     // x2, y2 (右下角座標)
        
        []() {
            // 按鈕被點擊時要做的事
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_START;  // 使用DataCenter中定義的常數
            printf("Button clicked! Changing to START state\n");
        }
    );
    
    buttons.push_back(startButton);
}

void InitialScreen::update() {
    // 更新介面元素
    for(auto button : buttons) {
        button->update();
    }
    
}

void InitialScreen::draw() {
    DataCenter *DC = DataCenter::get_instance();
    
    // 繪製白色背景
    al_clear_to_color(al_map_rgb(255, 255, 255));
    
    // 繪製介面元素
    
    for(auto button : buttons) {
        button->draw();
    }
}