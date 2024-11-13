#ifndef BOARD_H
#define BOARD_H

#include <iostream>
using namespace std;

class Board
{
private:
    char playerBoard[10][10];
    char enemyBoard[10][10];
public:

    Board();
    void showPlayerBoard();
    void showEnemyBoard();
    void showBothBoards();
    bool checkShipPlacementR(int length, int X, int Y);
    bool checkShipPlacement(int length, int X, int Y);
    void placingShip(int length, bool rotation, int X, int Y, int shipNum);
    char getChar(int X, int Y);
    void setCharP(int X, int Y, char c);
    void setCharE(int X, int Y, char c);
    ~Board();
};

#endif