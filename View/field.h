#ifndef FIELD_H
#define FIELD_H

#include "Units/unit.h"

#include <QGraphicsItem>
#include <iostream>

class Field : public QGraphicsItem
{
public:
    Field(unsigned row, unsigned col, int w = 40, int h = 40, QGraphicsItem* parent = nullptr);

    // Okvir polja, za ponovno isrtavanje.
    QRectF boundingRect() const override;

    //QPainterPath shape() const override;
    void paint(QPainter *painter,
                   const QStyleOptionGraphicsItem *option,
                   QWidget *widget) override;

    //TODO: Show info on mouse click.
    void mousePressEvent(QGraphicsSceneMouseEvent * event) override;

    //getters
    unsigned row() const;
    unsigned col() const;
    std::pair<int, int> position() const;
    Unit* unit() const;

    bool hasUnit() const;
    void placeUnit(Unit* u);
    void removeUnit();

private:
    const unsigned m_row,
        m_col;
    int m_width,
        m_height;
    Unit* m_unit;
    QColor m_color;
};

std::ostream& operator<<(std::ostream& out, const Field& value);

#endif // FIELD_H