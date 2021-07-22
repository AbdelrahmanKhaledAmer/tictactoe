#include "board.h"
#include <sstream>

using namespace std;

bool Board::update(int player, int num)
{
    if(game[num])
    {
        return false;
    }
    game[num] = player;
    return true;
}

int Board::winner()
{
    if(game[0] == game[1] && game[0] == game[2] && game[0] != 0)
    {// Row 1
        return game[0];
    }
    if(game[3] == game[4] && game[3] == game[5] && game[3] != 0)
    {// Row 2
        return game[3];
    }
    if(game[6] == game[7] && game[6] == game[8] && game[6] != 0)
    {// Row 3
        return game[6];
    }
    if(game[0] == game[3] && game[0] == game[6] && game[0] != 0)
    {// Col 1
        return game[0];
    }
    if(game[1] == game[4] && game[1] == game[7] && game[1] != 0)
    {// Col 2
        return game[1];
    }
    if(game[2] == game[5] && game[2] == game[8] && game[2] != 0)
    {// Col 3
        return game[2];
    }
    if(game[0] == game[4] && game[0] == game[8] && game[0] != 0)
    {// Diag LR
        return game[0];
    }
    if(game[2] == game[4] && game[2] == game[6] && game[2] != 0)
    {// Diag RL
        return game[2];
    }
    return 0;
}

bool Board::isDraw()
{
    for (int i = 0; i < 9; i++)
    {
        if(!game[i])
        {
            return false;
        }
    }
    return true;
}

void Board::reset()
{
    game.fill(0);
}

string Board::display()
{
    stringstream ss;
    ss << " ";
    for (int i = 0; i < 9; i++)
    {
        switch (game[i])
        {
            case 1: // Player 1 (X)
                ss << "X";
                break;
            case 2: // Player 2 (O)
                ss << "O";
                break;
            default:
                ss << i;
                break;
        }
        if(i == 8) {
            break;
        }
        if(i % 3 == 2) {
            ss << "\r\n---+---+---\r\n ";
        } else {
            ss << " | ";
        }
    }
    return ss.str();
}