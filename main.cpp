#include "SNL.h"

int main()
{
    srand(time(0));
    int n = 0, m = 0, t = 0;
    vector<int> SNL;

    // read input from file
    cin >> n >> m;
    SNL.reserve(m);

    while (m--)
        cin >> t,
            SNL.emplace_back(t);

    board mySNLBoard(n, SNL);

    mySNLBoard.startSNLGame(13);

    Player wonPlayer = mySNLBoard.winningPlayer();

    printf("\nPlayer %s has won this Snake and ladder game \n\tby being at position %d\n", wonPlayer.getName().c_str(), wonPlayer.getPosition());

    return 0;
}
