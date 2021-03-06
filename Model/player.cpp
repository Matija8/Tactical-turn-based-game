#include "player.h"

Player::Player(std::string name, QColor color)
    : m_color(color)
    , m_name(name)
{}


QColor Player::color() const
{
    return m_color;
}


std::string Player::name() const
{
    return m_name;
}


bool Player::operator==(Player& other) const
{
    return m_name == other.name();
}


bool Player::operator!=(Player& other) const
{
    return !(*this == other);
}
