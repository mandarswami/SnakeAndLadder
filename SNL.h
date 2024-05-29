/**
 *  AUTHOR - mandarswami
 *    FILE - SNL.h
 * CREATED - May 23(Thu),2024 at 01:20:08
 *    UUID - 6c60adc4-ac6f-4807-ba9a-46de5e16e0b1
 *
 * program to Simulate Snakes and Ladder game
 *
 **/

#include <iostream>
#include <vector>
#include <string>
#include <string_view>

using namespace std;

class Board;
class Player;
class Snake;
class Ladder;

class Player
{
    string name;
    int position;

public:
    Player(string &str) : name(str), position(0) {}
    void goTo(int &);
    void moveforward(int &);
    string getName();
    int getPosition();
};

class Board
{
    vector<Player> players;
    vector<Snake> snakes;
    vector<Ladder> ladders;

public:
    Board(int, vector<int> &);
    void startSNLGame(vector<int> &);
    Player &winningPlayer();
    bool isSnakePresent(Player &);
    bool isLadderPresent(Player &);
    bool checkIfGameFinished(Player &);
};

class Snake
{
    int mouth;
    int tail;

public:
    Snake(int &a, int &b) : mouth(a), tail(b) {}
    int getMouth();
    void bite(Player &);
};

class Ladder
{
    int start;
    int end;

public:
    Ladder(int &a, int &b) : start(a), end(b) {}
    int getStart();
    void climb(Player &);
};