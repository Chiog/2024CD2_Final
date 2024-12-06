#ifndef BUTTONDIFFIMPOSSIBLE_H_INCLUDED
#define BUTTONDIFFIMPOSSIBLE_H_INCLUDED

#include "Button.h"
#include <functional>
#include <string>


class ButtonDiffImpossible : public Button {
public:
    ButtonDiffImpossible(int x1, int y1, int x2, int y2)
        : Button(x1, y1, x2, y2, "Impossible", []() {  // text 在 lambda 前面
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_END;
            printf("GameMode:IMPOSSIBLE\n");
        }) {}
};

#endif


