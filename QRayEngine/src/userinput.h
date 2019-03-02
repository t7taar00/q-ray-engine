#ifndef USERINPUT_H
#define USERINPUT_H

#include <QKeyEvent>

class UserInput
{
public:
    UserInput();
    void keyPressEvent(QKeyEvent *event);
};

#endif // USERINPUT_H
