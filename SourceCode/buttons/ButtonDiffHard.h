#ifndef BUTTONDIFFHARD_H_INCLUDED
#define BUTTONDIFFHARD_H_INCLUDED

#include "Button.h"
#include <functional>
#include <string>


class ButtonDiffHard : public Button {
public:
    ButtonDiffHard(int x1, int y1, int x2, int y2)
        : Button(x1, y1, x2, y2, "Hard", []() {  // text 在 lambda 前面
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_START;
            printf("GameMode:HARD\n");
        }) {}
};

#endif


