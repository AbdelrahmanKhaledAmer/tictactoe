#ifndef BOARD_H
#define BOARD_H

#include <string>
#include <array>

using namespace std;

class Board
{
private:
    array<int, 9> game = { };
public:
    bool update(int player, int num);
    int winner();
    bool isDraw();
    void reset();
    string display();
};

#endif