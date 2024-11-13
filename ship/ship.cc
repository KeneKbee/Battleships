#include "ship.h"

Ship::Ship()
{

}

void Ship::shotsFired(int i)
{
    this->lengths[i] -= 1;
}

int Ship::getLength(int i)
{
    return this->lengths[i];
}

bool Ship::checker(int i)
{
    if (this->lengths[i] == 0)
    {
        return true;
    }
    return false;
}

bool Ship::allChecker()
{
    for (int i = 0; i < 10; i++)
    {
        if (this->lengths[i] != 0)
        {
            
            return false;
        }
    }
    return true;
}

Ship::~Ship()
{

}