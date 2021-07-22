#include "printer.h"
#include <iostream>

using namespace std;

void Printer::clear()
{
    system("CLS");
}

void Printer::write(string data)
{
    cout << data << endl;
}

void Printer::print(string data)
{
    clear();
    write(data);
}