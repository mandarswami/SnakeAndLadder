#include "SNL.h"

int Snake::getMouth()
{
    return mouth;
}

void Snake::bite(Player &p)
{
    p.goTo(tail);
}

int Ladder::getStart()
{
    return start;
}

void Ladder::climb(Player &p)
{
    p.goTo(end);
}