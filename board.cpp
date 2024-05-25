#include "SNL.h"

Board::Board(int n, vector<int> &SNL)
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

void Board::startSNLGame(vector<int> &diceThrows)
{
    auto p = players.begin();
    int i = 1;
    for (int &d : diceThrows)
    {
        printf("\n\tFor diceThrow(%d):%d \t For Player(%s):\n", i++, d, p->getName().c_str());
        statusOfPlayers();
        p->moveforward(d);
        printf("\tAfter MoveForward:\n");
        statusOfPlayers();

        bool y = true;
        while (y)
        {
            y = false;

            for (Snake &l : snakes)
                if (l.getMouth() == p->getPosition())
                {
                    l.bite(*p);
                    y = true;
                    printf("\tAfter bite:\n");
                    statusOfPlayers();
                    break;
                }

            if (y)
                continue;

            for (Ladder &l : ladders)
                if (l.getStart() == p->getPosition())
                {
                    l.climb(*p);
                    y = true;
                    printf("\tAfter climb:\n");
                    statusOfPlayers();
                    break;
                }
        }

        if (p->getPosition() == 100)
            return;

        if (d != 6)
            p++;
        if (p == players.end())
            p = players.begin();
    }
}

Player &Board::winningPlayer()
{
    Player &won = players[0];

    for (Player &p : players)
        if (p.getPosition() > won.getPosition())
            won = p;

    return won;
}

void Board::statusOfPlayers()
{
    printf("\t\tPositions of Players:\n\t\t\t");
    for (Player &p : players)
        printf("Player(%s):%d,\t", p.getName().c_str(), p.getPosition());
    printf("\n\n");
}