#include "SNL.h"

void Player::goTo(int &newPos)
{
    position = newPos;
}
void Player::moveforward(int &diceValue)
{
    if ((position + diceValue) <= 100)
    {
        position += diceValue;
        printf("\n✅🎲Player(%s) moved by %d, now at:%d🎲✅\n", name.c_str(), diceValue, position);
    }
    else
        printf("\n❌🎲Player(%s) couldn't move by %d, now at:%d🎲❌\n", name.c_str(), diceValue, position);
}

string Player::getName()
{
    return name;
}
int Player::getPosition()
{
    return position;
}