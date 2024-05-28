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

    for (int &d : diceThrows)
    {
        p->moveforward(d);

        if (checkIfGameFinished(*p))
            return;

        bool snakeBitten = false,
             ladderClimbed = false;

        while (true)
        {
            if (isSnakePresent(*p))
            {
                snakeBitten = true;
                continue;
            }

            if (isLadderPresent(*p))
                ladderClimbed = true;
            else
                break;
        };

        if (checkIfGameFinished(*p))
            return;

        if (snakeBitten)
            p++;
        else if ((d != 6) && (!ladderClimbed))
            p++;
        if (p == players.end())
            p = players.begin();
    }
}

bool Board::checkIfGameFinished(Player &p)
{
    if (p.getPosition() == 100)
    {
        printf("\n🏁🏁Game Finished!!🏁🏁\n");
        printf("\n🏆🏆Player(%s)🏆🏆 has won this Snake and ladder game \n\t by being first to reach at position:100\n", p.getName().c_str());
        return true;
    }
    return false;
}

bool Board::isSnakePresent(Player &p)
{
    for (Snake &s : snakes)
        if (s.getMouth() == p.getPosition())
        {
            s.bite(p);
            printf("\n 🐍 bite to Player(%s), now at %d\n", p.getName().c_str(), p.getPosition());
            return true;
        }
    return false;
}

bool Board::isLadderPresent(Player &p)
{
    for (Ladder &l : ladders)
        if (l.getStart() == p.getPosition())
        {
            l.climb(p);
            printf("\n 🪜 climb by Player(%s), now at %d\n", p.getName().c_str(), p.getPosition());
            return true;
        }

    return false;
}

Player &Board::winningPlayer()
{
    auto won = players.begin();

    for (auto p = players.begin(); p != players.end(); p++)
        if (p->getPosition() > won->getPosition())
            won = p;

    return *won;
}

void Board::statusOfPlayers()
{
    printf("\t\tPositions of Players:\n\t\t\t");
    for (Player &p : players)
        printf("Player(%s):%d,\t", p.getName().c_str(), p.getPosition());
    printf("\n\n");
}