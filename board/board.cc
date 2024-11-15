#pragma once
#include "board.h"

Board::Board()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            this->playerBoard[j][i]='-';
            this->enemyBoard[j][i]='-';

        }
    }
}

void Board::showPlayerBoard()
{
    cout << "Your board:" << endl << endl;

    for (int i = 0; i < 11; i++)
    {
        if (i==0)
        {
            cout << " " << " ";
        }
        else {
            char lett = 'A' + i-1;
            cout << lett << " ";
        }
        
        if (i>0)
        {
            for (int j = 0; j < 10; j++)
            {
                if (this->playerBoard[j][i-1] == '-')
                {
                    cout << "\033[1;44m" << '-' << ' ' << "\033[0m";
                }
                else if(this->playerBoard[j][i-1] == ' ')
                {
                    cout << "\033[1;46m" << ' ' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else if (this->playerBoard[j][i-1] == 'X')
                {
                    cout << "\033[43m\033[30m" << 'X' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else if (this->playerBoard[j][i-1] == '!')
                {
                    cout << "\033[43m\033[30m" << '!' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else {
                    cout << "\033[1;44m" << 'S' << ' ' << "\033[0m";
                }
            }

        }
        else {

            for (int j = 0; j < 10; j++)
            {
                cout << j+1 << " ";
            }

        }
        cout << endl;
    }
    cout << endl;
}

void Board::showEnemyBoard()
{
    cout << "Enemy board:" << endl << endl;
    for (int i = 0; i < 11; i++)
    {
        if (i==0)
        {
            cout << " " << " ";
        }
        else {
            char lett = 'A' + i-1;

            cout << lett << " ";
        }
        
        if (i>0)
        {
            for (int j = 0; j < 10; j++)
            {
                if (this->enemyBoard[j][i-1] == '-')
                {
                    cout << "\033[1;44m" << '-' << ' ' << "\033[0m";
                }
                else if(this->enemyBoard[j][i-1] == ' ')
                {
                    cout << "\033[1;46m" << ' ' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else if (this->enemyBoard[j][i-1] == 'X')
                {
                    cout << "\033[43m\033[30m" << 'X' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else if (this->enemyBoard[j][i-1] == '!')
                {
                    cout << "\033[43m\033[30m" << '!' << "\033[1;44m" << ' ' << "\033[0m";
                }
                else {
                    cout << "\033[1;44m" << 'S' << ' ' << "\033[0m";
                }
            }
        }
        else {
            for (int j = 0; j < 10; j++)
            {
                cout << j+1 << " ";
            }
            
        }
        cout << endl;
    }
    cout << endl;
}

void Board::showBothBoards()
{
    showPlayerBoard();
    showEnemyBoard();
}

bool Board::checkShipPlacementR(int length, int X, int Y)
{
    if (Y+length>9)
    {
        return false;
    }
    for (int i = Y; i <= length+Y; i++)
    {
        if (this->playerBoard[X][i] != '-')
        {
            return false;
        }
    }


    if(X>0 && Y>0)
    {
        for (int i = Y; i <= length+Y; i++)
        {
            if (this->playerBoard[X-1][i] != '-')
            {
                return false;
            }
            if (X!=9)
            {
                if (this->playerBoard[X+1][i] != '-')
                {
                    return false;
                }
            }
        }
        if (this->playerBoard[X-1][Y-1] != '-' || this->playerBoard[X][Y-1] != '-')
        {
            return false;
        }
        if (X!=9)
        {
            if (this->playerBoard[X+1][Y-1] != '-')
            {
                return false;
            }
        }

        if (Y+length!=9)
        {
            if (this->playerBoard[X-1][Y+length+1] != '-' || this->playerBoard[X][Y+length+1] != '-')
            {
                return false;
            }
            if (X!=9)
            {
                if (this->playerBoard[X+1][Y+length+1] != '-')
                {
                    return false;
                }
                
            }
        }
    }

    if (X!=0 && Y==0)
    {
        if (this->playerBoard[X-1][Y+length+1] != '-' || this->playerBoard[X][Y+length+1] != '-')
        {
            return false;
        }
        if (X!=9)
        {
            if (this->playerBoard[X+1][Y+length+1] != '-')
            {
                return false;
            }
            
        }
        
        for (int i = Y; i <= length+Y; i++)
        {
            if (this->playerBoard[X-1][i] != '-')
            {
                return false;
            }
            if (X!=9)
            {
                if (this->playerBoard[X+1][i] != '-')
                {
                    return false;
                }
            }
            
        }
    }

    if(X==0 && Y!=0)
    {
        if (this->playerBoard[X+1][Y-1] != '-' || this->playerBoard[X][Y-1] != '-')
        {
            return false;
        }
        else if(Y+length<9)
        {
            if (this->playerBoard[X+1][Y+length+1] != '-' || this->playerBoard[X][Y+length+1] != '-')
            {
                return false;
            }
        }
        
        for (int i = Y; i <= length+Y; i++)
        {
            if (this->playerBoard[X+1][i] != '-')
            {
                return false;
            }
        }
    }

    if (X==0 && Y==0)
    {
        for (int i = Y; i <= length+Y; i++)
        {
            if (this->playerBoard[X+1][i] != '-')
            {
                return false;
            }
            
        }
        
        if (this->playerBoard[X][Y+length+1] != '-' || this->playerBoard[X+1][Y+length+1] != '-')
        {
            return false;
        }
    }
    
    return true;
}

bool Board::checkShipPlacement(int length, int X, int Y)
{
    if (X+length>9)
    {
        return false;
    }
    for (int i = X; i <= length+X; i++)
    {
        if (this->playerBoard[i][Y] != '-')
        {
            return false;
        }
    }


    if(X>0 && Y>0)
    {
        for (int i = X; i <= length+X; i++)
        {
            if (this->playerBoard[i][Y-1] != '-')
            {
                return false;
            }
            if (Y!=9)
            {
                if (this->playerBoard[i][Y+1] != '-')
                {
                    return false;
                }
            }
        }
        if (this->playerBoard[X-1][Y-1] != '-' || this->playerBoard[X-1][Y] != '-')
        {
            return false;
        }
        if (Y!=9)
        {
            if (this->playerBoard[X-1][Y+1] != '-')
            {
                return false;
            }
        }
        
        if (X+length!=9)
        {
            if (this->playerBoard[X+length+1][Y-1] != '-' || this->playerBoard[X+length+1][Y] != '-')
            {
                return false;
            }
            if (Y!=9)
            {
                if (this->playerBoard[X+length+1][Y+1] != '-')
                {
                    return false;
                }
            }
        }
    }

    if (X==0 && Y!=0)
    {
        if (this->playerBoard[X+length+1][Y-1] != '-' || this->playerBoard[X+length+1][Y] != '-')
        {
            return false;
        }
        if (Y!=9)
        {
            if (this->playerBoard[X+length+1][Y+1] != '-')
            {
                return false;
            }
        }
        
        for (int i = X; i <= length+X; i++)
        {
            if (this->playerBoard[i][Y-1] != '-')
            {
                return false;
            }
            if (Y!=9)
            {
                if (this->playerBoard[i][Y+1] != '-')
                {
                    return false;
                }
            }
        }
    }

    if(X!=0 && Y==0)
    {
        if (this->playerBoard[X-1][Y+1] != '-' || this->playerBoard[X-1][Y] != '-')
        {
            return false;
        }
        else if(X+length<9)
        {
            if (this->playerBoard[X+length+1][Y+1] != '-' || this->playerBoard[X+length+1][Y] != '-')
            {
                return false;
            }
        }
        
        for (int i = X; i <= length+X; i++)
        {
            if (this->playerBoard[i][Y+1] != '-')
            {
                return false;
            }
        }
    }

    if (X==0 && Y==0)
    {
        for (int i = X; i <= length+X; i++)
        {
            if (this->playerBoard[i][Y+1] != '-')
            {
                return false;
            }
            
        }
        
        if (this->playerBoard[X+length+1][Y] != '-' || this->playerBoard[X+length+1][Y+1] != '-')
        {
            return false;
        }
    }
    
    return true;
}

void Board::placingShip(int length, bool rotation, int X, int Y, int shipNum)
{
    if (rotation == true)
    {
        for (int i = 0; i < length; i++)
        {
            this->playerBoard[X][Y+i] = shipNum+48; // 48 is the ASCII value of 0
        }
    }
    else {
        for (int i = 0; i < length; i++)
        {
            this->playerBoard[X+i][Y] = shipNum+48; // 48 is the ASCII value of 0
        }

    }
}

char Board::getChar(int X, int Y)
{
    return this->playerBoard[X][Y];
}

void Board::setCharP(int X, int Y, char c)
{
    this->playerBoard[X][Y] = c;
}

void Board::setCharE(int X, int Y, char c)
{
    this->enemyBoard[X][Y] = c;
}

Board::~Board()
{
}