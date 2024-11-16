#include "menu.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>

Menu::Menu()
{
}

void Menu::sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

int Menu::showIntro()
{
    int input;
    while (true)
    {
        system("cls");
        cout << "Welcome to Battleships!" << endl << endl;
        cout << "1. Tutorial" << endl;
        cout << "2. Play" << endl;
        cout << "3. Change first player name" << endl;
        cout << "4. Change second player name" << endl;
        cout << "5. Credits" << endl;
        cout << "6. Quit" << endl << endl;
        
        cin >> input;
        system("cls");
        if (cin.fail() || input < 1 || input > 6) // Check if input is valid
        {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
        }
        else {
            break;
        }
    }
    
    
    return input;
}

void Menu::showTutorial()
{
    system("cls");
    cout << "Tutorial:" << endl << endl;
    sleep(1000);
    cout << "You are the captain of the navy, and you must navigate through a sea of enemy ships." << endl;
    sleep(4000);
    cout << "You will be given a map of the sea, and you must use your brain to survive." << endl << endl;
    sleep(4000);
    cout << "Part 1: You will have to make decisions wisely, and you will have to place your ships strategically and NOT like a fool." << endl;
    sleep(4000);
    cout << "\033[38;5;214mThe Fool.\033[0m We all know a fool when we see one. Don't we? Innocence and freedom? Or recklessness and risk-taking? Spontaneity... Actions without thought, but the consequences to match. Think. Think and don't lose." << endl << endl;
    sleep(4000);
    cout << "Part 2: You will get the stength to command your own navy and shoot the enemy." << endl;
    sleep(4000);
    cout << "\033[38;5;214mStrength.\033[0m Strength can be surprising. Knowing the power of your own strength can lead you to victory." << endl << endl;
    sleep(4000);
    cout << "To perform both actions you need to know how to tell your navy where to shoot:" << endl << endl;
    sleep(2000);
    cout << "Left to Right (X) values: 1-10" << endl << endl;
    sleep(2000);
    cout << "Top to Bottom (Y) values: A-J  OR  a-j" << endl << endl;
    sleep(2000);
    cout << "Rotation values: true - t - 1 - yes - y  OR  false - f - 0 - no - n" << endl << endl;
    sleep(4000);
    cout << "Also you must know how to read specific values on the map:" << endl << endl;
    sleep(2000);
    cout << "'S' Means Ship" << endl << endl;
    sleep(2000);
    cout << "'\033[1;46m" << ' ' << "\033[0m' (blank cell with this color) means a miss" << endl << endl;
    sleep(2000);
    cout << "'X' means that the ship was hit" << endl << endl;
    sleep(2000);
    cout << "'!' means that the ship has sunk" << endl << endl;
    sleep(4000);
    system("pause");
    sleep(1000);
    cout << endl << "But remember!" << endl << endl;
    sleep(1000);
    cout << "the attempt to win is sometimes like spinning a wheel of fortune." << endl;
    sleep(4000);
    cout << "\033[38;5;214mWheel of Fortune.\033[0m After all, fortune is nothing but a spinning wheel. Sometimes you have to take a chance. Karma works in mysterious ways, but it favors those who pay attention." << endl << endl;
    sleep(4000);
    system("pause");
    system("cls");
}

void Menu::showEnding(Board board1, Board board2, Player player1, Player player2)
{
    cout << "You won! - all ships have been sunk!" << endl << endl;
    sleep(2000);
    system("cls");
    cout << "You won! - all ships have been sunk!" << endl << endl;
    system("pause");
    system("cls");
    cout << "\033[38;5;214m" << player1.getName() << "\033[0m:" << endl << endl <<"Max streak: " << player1.getMaxStreak() << "\t Score: " << player1.getScore() << endl << endl << "Board: " << endl << endl;
    board1.showPlayerBoard();
    cout << endl << endl;
    cout << "\033[38;5;214m" << player2.getName() << "\033[0m:" << endl << endl <<"Max streak: " << player2.getMaxStreak() << "\t Score: " << player2.getScore() << endl << endl << "Board: " << endl << endl;
    board2.showPlayerBoard();
    cout << endl << endl;
}

Menu::~Menu()
{
}
