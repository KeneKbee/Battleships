#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
private:
    int length;
public:
    Ship(int length);
    void shotsFired();
    int getLength();
    bool checker();
    ~Ship();
};

#endif