
#ifndef BUTTON_H_INCLUDED
#define BUTTON_H_INCLUDED

#include "../Object.h"
#include <functional>
#include <string>  // 需要加入 string 標頭檔

class Button : public Object {
public:
    Button(int x1, int y1, int x2, int y2, const std::string& text, std::function<void()> onClick);  // 修改建構子
    //1204up 修改建構子，新增text
    void update();
    void draw();

private:
    std::function<void()> onClick;
    bool isHovered;
    std::string text;
};

#endif

