#ifndef BUTTONINITSTART_H_INCLUDED
#define BUTTONINITSTART_H_INCLUDED

#include "Button.h"

class ButtonInitStart : public Button {
public:
    ButtonInitStart(int x1, int y1, int x2, int y2)
        : Button(x1, y1, x2, y2, "START", []() {
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_DIFFICULTY;
            printf("Game Starting!\n");
        }) {}
};

#endif
