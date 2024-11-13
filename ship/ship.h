#ifndef SHIP_H
#define SHIP_H

#include <iostream>
using namespace std;

class Ship
{
private:
    int lengths[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
public:
    Ship();
    void shotsFired(int i);
    int getLength(int i);
    bool checker(int i);
    bool allChecker();
    ~Ship();
};

#endif