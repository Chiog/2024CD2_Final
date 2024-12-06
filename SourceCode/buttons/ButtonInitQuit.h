#ifndef BUTTONINITQUIT_H_INCLUDED
#define BUTTONINITQUIT_H_INCLUDED

#include "Button.h"
#include <functional>
#include <string>


class ButtonInitQuit : public Button {
public:
    ButtonInitQuit(int x1, int y1, int x2, int y2)
        : Button(x1, y1, x2, y2, "QUIT", []() {  // text 在 lambda 前面
            DataCenter *DC = DataCenter::get_instance();
            DC->nextState = DC->STATE_END;
            printf("Game End!\n");
        }) {}
};

#endif


