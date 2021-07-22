#ifndef PRINTER_H
#define PRINTER_H

#include <string>

using namespace std;

class Printer
{
private:
    void clear();
    void write(string data);
public:
    void print(string data);
};

#endif