#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
using namespace std;

class Player
{
private:
    string name;
    int score=0;
    int maxStreak=0;
public:
    Player(string name);
    void clear();
    void changeName();
    string getName();
    void switchPlayer();
    int getMaxStreak();
    void setMaxStreak(int newStreak);
    int getScore();
    void setScore();
    void goodbye();
    ~Player();
};

#endif