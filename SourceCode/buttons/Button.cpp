#include "Button.h"
#include "../shapes/Rectangle.h"
#include "../data/DataCenter.h"
#include <allegro5/allegro_primitives.h>

#include "../data/FontCenter.h"          // 1204up for text
#include <allegro5/allegro_font.h>       // 1204up for text



// 在 Button.cpp 中修改建構子和 draw 函數
//1204upstart
Button::Button(int x1, int y1, int x2, int y2, const std::string& text, std::function<void()> onClick)
    : onClick(onClick), text(text) {
    shape.reset(new Rectangle(x1, y1, x2, y2));
    isHovered = false;
}
//1204up.end
void Button::update() {
    DataCenter *DC = DataCenter::get_instance();
    Rectangle* rect = static_cast<Rectangle*>(shape.get());
    
    // 檢查滑鼠是否在按鈕上
    isHovered = DC->mouse.overlap(*rect);
    
    
    // 檢查點擊
    if(isHovered && DC->mouse_state[1] && !DC->prev_mouse_state[1]) {
        printf("clicked!\n");
        onClick();
    }
}

void Button::draw() {
    Rectangle* rect = static_cast<Rectangle*>(shape.get());
    ALLEGRO_COLOR color = isHovered ? 
        al_map_rgb(200, 200, 200) : // 滑鼠懸停時的顏色
        al_map_rgb(0, 0, 255);  // 預設顏色
    
    al_draw_filled_rectangle(
        rect->x1, rect->y1,
        rect->x2, rect->y2,
        color
    );

    // 繪製文字1204upstart
    FontCenter *FC = FontCenter::get_instance();
    int centerX = (rect->x1 + rect->x2) / 2;
    int centerY = (rect->y1 + rect->y2) / 2;
    al_draw_text(
        FC->caviar_dreams[FontSize::MEDIUM],
        al_map_rgb(255, 255, 255),  // 白色文字
        centerX,
        centerY - FontSize::MEDIUM/2,  // 垂直置中
        ALLEGRO_ALIGN_CENTRE,
        text.c_str()
    );
    //1204upend
}

