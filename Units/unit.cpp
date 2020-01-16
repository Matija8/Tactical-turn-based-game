#include "unit.h"
#include <QPainter>

Unit::Unit(int HP,int AP,int initiative,int row,int col, QGraphicsItem* parent)
    : QGraphicsItem(parent)
    , m_max_HP(HP)
    , m_max_AP(AP)
    , m_initiative(initiative)
    , m_row(row)
    , m_col(col)
{
    setId();
    m_remaining_HP = m_max_HP;
    m_remaining_AP = m_max_AP;
    //TODO: z depth?
    //TODO: get setPos parameters from a source for both unit and field:

    qreal grid_left = 0, grid_top = 0;
    int m_field_width = 40;
    int m_field_height = 40;
    this->setPos(grid_left + row * m_field_width,
                 grid_top  + col * m_field_height);
}


unsigned Unit::next_id = 0;


void Unit::setId()
{
    m_id = Unit::next_id++;
}


unsigned Unit::getId() const
{
    return m_id;
}


QRectF Unit::boundingRect() const
{
    //TODO: m_width...
    int m_width = 30;
    int m_height = 30;
    return QRectF(-(m_width/2), -(m_height/2)
                  , m_width, m_height);
}

void Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *)
{
    Q_UNUSED(option)
    int m_width = 30;
    int m_height = 30;
    QColor m_color = QColor(Qt::red);

    QPainterPath path;
    path.addEllipse(-(m_width/2), -(m_height/2)
                 , m_width, m_height);
    QPen pen(Qt::black, 3);
    painter->setPen(pen);
    painter->fillPath(path, m_color);
    painter->drawPath(path);
}


std::pair<int, int> Unit::position() const
{
    return std::pair(m_row, m_col);
}


std::pair<int, int> Unit::health() const
{
    return std::pair(m_remaining_HP, m_max_HP);
}


void Unit::updateHealth(int change)
{
    int new_HP = m_remaining_HP + change;
    if(new_HP > m_max_HP) {
        new_HP = m_max_HP;
    }
    else if(new_HP < 0) {
        //TODO: kill unit.
        new_HP = 0;
    }
    m_remaining_HP = new_HP;
}


std::string Unit::info() const
{
    return "Unit says hello!\n"
            "Id: " + std::to_string(getId()) + "; "
            "Health: (" + std::to_string(health().first) + '/' + std::to_string(health().second) + ");";
}


std::ostream& operator<<(std::ostream& out, const Unit& u)
{
    return out << u.info();
}
