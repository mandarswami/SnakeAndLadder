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

class board;
class Player;
class Snake;
class Ladder;

class Player
{
    string name;
    int position;

public:
    Player(string &str) : position(0), name(str) {}
    void goTo(int &k) { position = k; }
    void moveforward(int &k) { position += k; }
    string getName() { return name; }
    int getPosition() { return position; }
};
class board
{
    vector<Player> players;
    vector<Snake> snakes;
    vector<Ladder> ladders;

public:
    board(int, vector<int> &);
    void startSNLGame(const int &);
    Player &winningPlayer();
};

class Snake
{
    int mouth;
    int tail;

public:
    Snake(int &a, int &b) : mouth(a), tail(b) {}
    int getMouth() { return mouth; }
    void bite(Player &p) { p.goTo(tail); }
};

class Ladder
{
    int start;
    int end;

public:
    Ladder(int &a, int &b) : start(a), end(b) {}
    int getStart() { return start; }
    void climb(Player &p) { p.goTo(end); }
};