#pragma once
#include "player.h"


Player::Player(string name)
{
    this->name=name;
    cout << "Hello " << "\033[38;5;214m" << this->name << "\033[0m" << endl;
}

void Player::clear()
{
    system("cls");
}

void Player::changeName()
{
    cout << "Your old name is " << "\033[38;5;214m" << this->name << "\033[0m" << endl << endl;
    cout << "Enter your new name: ";
    cin >> this->name;
    clear();
}

void Player::switchPlayer()
{
    clear();
    char ready;
    while(true)
    {
        cout << "Next screen is for player \"" << "\033[38;5;214m" << this->name << "\033[0m" << "\" eyes only!" << endl << endl;
        cout << "Ready to proceed? Y/N: ";
        cin >> ready;

        if (ready == 'Y' || ready == 'y')
        {
            break;
        }
        clear();
    }
    clear();
}

int Player::getMaxStreak()
{
    return this->maxStreak;
}

void Player::setMaxStreak(int newStreak)
{
    this->maxStreak=newStreak;
}

int Player::getScore()
{
    return this->score;
}

void Player::setScore()
{
    this->score++;
}

void Player::goodbye()
{
    cout << "Goodbye " << this->name << endl;
}

Player::~Player()
{
}