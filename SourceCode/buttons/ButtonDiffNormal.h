#ifndef BUTTONDIFFNORMAL_H_INCLUDED
#define BUTTONDIFFNORMAL_H_INCLUDED

#include "Button.h"
#include <functional>
#include <string>


class ButtonDiffNormal : public Button {
public:
    ButtonDiffNormal(int x1, int y1, int x2, int y2)
        : Button(x1, y1, x2, y2, "Normal", []() {  // text 在 lambda 前面
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_START;
            printf("GameMode:Normal\n");
        }) {}
};

#endif


