
#include "data/DataCenter.h"
#include <allegro5/allegro_primitives.h>
#include "Game.h"

#include "DifficultyScreen.h"
#include "buttons/ButtonDiffNormal.h"    // 1206up
#include "buttons/ButtonDiffHard.h"    // 1206up
#include "buttons/ButtonDiffImpossible.h"    // 1206up
void DifficultyScreen::init() {
    // 創建開始遊戲按鈕
    Button* normalButton = new ButtonDiffNormal(
        300, 200,     // x1, y1 (開始按鈕)
        500, 250      // x2, y2
    );
    
    // 創建退出遊戲按鈕
    Button* hardButton = new ButtonDiffHard(
        300, 300,     // x1, y1 (退出按鈕)
        500, 350      // x2, y2
    );
    
    buttons.push_back(normalButton);
    buttons.push_back(hardButton);
}

void DifficultyScreen::update() {
    // 更新介面元素
    for(auto button : buttons) {
        button->update();
    }
    
}

void DifficultyScreen::draw() {
    //DataCenter *DC = DataCenter::get_instance();
    
    // 繪製白色背景
    al_clear_to_color(al_map_rgb(100, 0, 255));
    
    // 繪製介面元素
    
    for(auto button : buttons) {
        button->draw();
    }
}

