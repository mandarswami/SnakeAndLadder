#include "SNL.h"

int main()
{
    int noOfPlayers = 0, totalSnakesLadders = 0, noOfDiceThrows = 0;

    // read input from file
    cin >> noOfPlayers >> totalSnakesLadders >> noOfDiceThrows;

    vector<int> SNL(totalSnakesLadders, 0);
    vector<int> diceThrows(noOfDiceThrows, 0);

    for (int i = 0; i < totalSnakesLadders; i++)
        cin >> SNL[i];

    for (int i = 0; i < noOfDiceThrows; i++)
        cin >> diceThrows[i];

    Board mySNLBoard(noOfPlayers, SNL);

    mySNLBoard.startSNLGame(diceThrows);

    Player wonPlayer = mySNLBoard.winningPlayer();

    printf("\nPlayer %s has won this Snake and ladder game \n\tby being at position %d\n", wonPlayer.getName().c_str(), wonPlayer.getPosition());

    return 0;
}
