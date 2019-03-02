#include "userinput.h"

UserInput::UserInput()
{

}

void UserInput::keyPressEvent(QKeyEvent *event)
{
    event->accept();

    if(event->key() == Qt::Key_A)
        // do something
    if(event->key() == Qt::Key_D)
        // do something
    if(event->key() == Qt::Key_W)
        // do something
    if(event->key() == Qt::Key_S)
        // do something
    if(event->key() == Qt::Key_Q)
        // do something
    if(event->key() == Qt::Key_E)
        // do something
}
