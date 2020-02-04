#ifndef LEVELS_H
#define LEVELS_H

#include "Controller/gamecontroller.h"
#include "View/ui.h"

#include <QLabel>
#include <QPushButton>


GameController* createLevel1(ui ui);
GameController* createLevel2(ui ui);
GameController* createLevel3(ui ui);


#endif // LEVELS_H
