#include "ship.h"

Ship::Ship(int length)
{
    this->length=length;
}

void Ship::shotsFired()
{
    this->length -= 1;
}

int Ship::getLength()
{
    return this->length;
}

bool Ship::checker()
{
    if (this->length == 0)
    {
        return true;
    }
    return false;
}

/*bool Ship::allChecker()
{
    for (int i = 0; i < 10; i++)
    {
        if (this->lengths[i] != 0)
        {
            
            return false;
        }
    }
    return true;
}*/

Ship::~Ship()
{

}