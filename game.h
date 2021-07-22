#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "printer.h"

using namespace std;

class Game
{
private:
    Printer printer;
    Board board;
    bool player1 = true;
    bool error_flag = false;

    void display();
    bool endCondition();
    bool turn();

public:
    void gameLoop();
};

#endif