#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Units/unit.h"
#include "View/grid.h"
#include "View/actionbutton.h"
#include "unitqueue.h"
#include "View/ui.h"

#include <vector>
#include <QPushButton>


//class UnitQueue;
enum ControllerState {init, action};


class GameController : public QObject
{
    Q_OBJECT

private:
    UnitQueue* m_queue;
    Unit* m_active_unit;
    Grid* m_grid;
    unsigned m_turn;
    int m_field_width = 40,
        m_field_height = 40; //TODO: Make uniform with grid!
    ControllerState m_state = init;
    std::vector<Player*>* m_players;
    // UI:
    QLabel* m_infoLabel;

public:
    GameController(ui ui, QObject* parent);

    ~GameController();
    GameController(const GameController & other) = delete;
    const GameController& operator= (const GameController & other) = delete;


public:
    void setGrid(Grid* g);
    bool addUnit(Unit* u);
    Unit* activeUnit() const;
    void startGame();

    void add_pb_Action(ActionButton* pb_action);

    void setInfo(std::string msg);
    QString getInfo();

    bool moveUnit (Unit* unit, std::pair<int, int> position);
    //This is for drawing units, setPos()!
    std::pair<qreal, qreal> calculatePos(unsigned row, unsigned col) const;
    std::pair<qreal, qreal> calculatePos(std::pair<int, int> position) const;
    void setState(ControllerState state);
    std::vector<Action*>* getCurrentActions();
    std::string defaultInfo() const;
    void addPlayer(Player*);

private:
    void resetActions();
    void updatePlayer();

private:
    void noActiveUnitError();


public slots:
    void endTurn();
    void actionButtonPressed(int button_number);
    void actionButtonPressed(Action* action);

signals:
    void changeInfo(const QString&);
    void changeInfoPlayer(const QString&);
    void resetActionsOnButtons(std::vector<Action*>* Actions);

};







#endif // GAMECONTROLLER_H
