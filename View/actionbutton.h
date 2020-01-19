#ifndef ACTIONBUTTON_H
#define ACTIONBUTTON_H

#include <QPushButton>
#include "Actions/action.h"

class ActionButton : public QPushButton
{

    Q_OBJECT

public:
    ActionButton(int button, QWidget* parent);
    //void setText(std::string text);
    //void setAction(Action* action);

public slots:
    void forwardAction(); //wrapper for clicked() signal.
    void setActions(std::vector<Action>* Actions);

signals:
    //TODO: redef clicked()?
    void actionUsed(Action* action);
    void actionUsed(int button);

private:
    Action* m_action;
    int m_button;
};

#endif // ACTIONBUTTON_H
