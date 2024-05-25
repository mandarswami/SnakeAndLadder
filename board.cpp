#include "SNL.h"

board::board(int n, vector<int> &SNL)
{
    players.reserve(n);

    for (int i = 0; i < n; i++)
    {
        string s = "A";
        s[0] += i;
        players.emplace_back(Player(s));
    }

    for (int i = 0; i < SNL.size(); i += 2)
        if (SNL[i] < SNL[i + 1])
            ladders.emplace_back(Ladder(SNL[i], SNL[i + 1]));
        else
            snakes.emplace_back(Snake(SNL[i], SNL[i + 1]));
}

void board::startSNLGame(const int &diceThrows)
{
    auto p = players.begin();
    for (int i = 0; i < diceThrows; i++)
    {
        int thro = rand() % 6 + 1;
        p->moveforward(thro);

        bool y = true;
        while (y)
        {
            y = false;

            for (Snake &l : snakes)
                if (l.getMouth() == p->getPosition())
                {
                    l.bite(*p);
                    y = true;
                    break;
                }

            if (y)
                continue;

            for (Ladder &l : ladders)
                if (l.getStart() == p->getPosition())
                {
                    l.climb(*p);
                    y = true;
                    break;
                }
        }

        if (thro != 6)
            p++;
        if (p == players.end())
            p = players.begin();
    }
}

Player &board::winningPlayer()
{
    Player &won = players[0];

    for (Player &p : players)
        if (p.getPosition() > won.getPosition())
            won = p;

    return won;
}