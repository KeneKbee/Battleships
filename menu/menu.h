#ifndef MENU_H
#define MENU_H

#include "../board/board.cc"
#include "../player/player.cc"

class Menu
{
public:
    Menu();
    void sleep(int milliseconds);
    int showIntro();
    void showTutorial();
    void showEnding(Board board1, Board board2, Player player1, Player player2);
    ~Menu();
};

#endif