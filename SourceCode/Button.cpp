#include "Button.h"
#include "shapes/Rectangle.h"
#include "data/DataCenter.h"
#include <allegro5/allegro_primitives.h>

Button::Button(int x1, int y1, int x2, int y2, std::function<void()> onClick)
    : onClick(onClick) {
    shape.reset(new Rectangle(x1, y1, x2, y2));
    isHovered = false;
}

void Button::update() {
    DataCenter *DC = DataCenter::get_instance();
    Rectangle* rect = static_cast<Rectangle*>(shape.get());
    
    // 檢查滑鼠是否在按鈕上
    isHovered = DC->mouse.overlap(*rect);
    
    // 檢查點擊
    if(isHovered && DC->mouse_state[1] && !DC->prev_mouse_state[1]) {
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
}