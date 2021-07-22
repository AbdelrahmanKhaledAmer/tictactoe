#include "game.h"
#include <iostream>
#include <sstream>

string error_message = "Something went wrong.Let's try again!\r\n";
string input_message = "Please input a number for one of the empty cells or type -1 to exit\r\n";

void Game::gameLoop()
{
    while (true)
    {
        display();
        if(endCondition())
        {
            cin.get();
            cin.get();
            cin.clear();
            cin.ignore();
            player1 = true;
            board.reset();
            display();
        }
        if(!turn())
        {
            break;
        }
    }
}

void Game::display()
{
    // Present user with relvant text
    stringstream ss;
    if(error_flag)
    {
        ss << error_message;
    }
    ss << "It's Player " << (player1? "1" : "2") << "'s turn!\r\n";
    ss << input_message;
    ss << board.display();
    printer.print(ss.str());
}

bool Game::endCondition()
{
    // check for winners or draw
    int winner = board.winner();
    if(board.isDraw())
    {
        cout << "Draw game! Press enter to retry." << endl;
        return true;
    } else if (winner) {
        cout << "Congratulation to player " << winner << "! Press enter to retry." << endl;
        return true;
    }
    return false;
}

bool Game::turn()
{
    // Take (correct) input
    int cell;
    if(cin >> cell)
    {
        if(cell > 8 || cell < 0)
        {
            if(cell == -1)
            {
                return false;
            }
            error_flag = true;
        } else if(board.update(player1 ? 1 : 2, cell)) {
            player1 = !player1;
            error_flag = false;
        }
    } else {
        cin.clear();
        cin.ignore();
        error_flag = true;
    }
    return true;
}