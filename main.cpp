#include "board/board.cc"
#include "player/player.cc"
#include "ship/ship.cc"
#include <iostream>
#include <thread>
#include <chrono>
#include <limits>
#include <algorithm>

using namespace std;

void sleep(int milliseconds)
{
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}

void clear()
{
    system("cls");
}

int showIntro()
{
    int input;
    while (true)
    {
        clear();
        cout << "Welcome to Battleships!" << endl << endl;
        cout << "1. Tutorial" << endl;
        cout << "2. Play" << endl;
        cout << "3. Change first player name" << endl;
        cout << "4. Change second player name" << endl;
        cout << "5. Credits" << endl;
        cout << "6. Quit" << endl << endl;
        
        cin >> input;
        clear();
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

void showTutorial()
{
    clear();
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
    clear();
}

int getXCoordinate(string text)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any excess input from previous cins (e.g Enter X: 1a - the 'a' will get ignored)
    int input;
    while (true)
    {
        cout << "Enter X: ";
        cin >> input;

        if (cin.fail() || input < 1 || input > 10) // Check if input is valid
        {
            cin.clear(); // clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore invalid input
            cerr << "Invalid input. Please enter a valid number (1-10)." << endl << endl;
            sleep(2000);
        }
        else {
            break;
        }
    }
    return input-1;
}

int getYCoordinate(string text)
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any excess input from previous cins (e.g Enter X: 1a - the 'a' will get ignored)
    char input;
    while(true)
    {
        cout << "Enter Y: ";
        cin >> input;

        if (toupper(input)<65 || toupper(input)>74) // Check if input is valid 
        {
            cerr << "Invalid input. Please enter a valid letter (A-J)." << endl << endl;
        }
        else {
            break;
        }
    }
    return toupper(input)-64-1;
}

bool getRotation()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ignore any excess input from previous cins (e.g Enter X: 1a - the 'a' will get ignored)
    string input;
    while (true)
    {
        cout << "Enter rotation (false: left to right , true: top to bottom): ";
        cin >> input;

        transform(input.begin(), input.end(), input.begin(), ::tolower); // Convert the user input to lowercase to handle case-insensitive comparisons

        if (input == "true" || input == "t" || input == "1" || input == "yes" || input == "y")
        {
            return true;
        }
        else if(input == "false" || input == "f" || input == "0" || input == "no" || input == "n")
        {
            return false;
        }
        else {
            cerr << "Invalid input. Please enter a valid value." << endl << endl;
            sleep(2000);
        }
    }
}

bool shipAllChecker(Ship ships[])
{
    for (int i = 0; i < 10; i++)
    {
        if (ships[i].checker()==false)
        {
            return false;
        }
    }
    return true;
}

Board placeShips(Board board, Ship ships[])
{
    int count=0;
    int x;
    int y;
    int length;
    int rotation;
    while (count < 10)
    {
        length = ships[count].getLength();
        
        cout << "Ships remaining: " << (count-10)*(-1) << endl << endl;
        cout << "Length: " << length << endl << endl;
        x = getXCoordinate("X");
        y = getYCoordinate("Y");
        if (length != 1)
        {
            rotation = getRotation();
        }
        else {
            rotation = true;
        }

        if (rotation==true)
        {
            if (board.checkShipPlacementR(length-1, x, y)==true)
            {
                board.placingShip(length, rotation, x, y, count);
                count++;
            }
            else {
                cerr << "Invalid placement. Please try again." << endl;
                sleep(2000);
                clear();
            }
        }
        else {
            if (board.checkShipPlacement(length-1, x, y)==true)
            {
                board.placingShip(length, rotation, x, y, count);
                count++;
            }
            else {
                cerr << "Invalid placement. Please try again." << endl;
                sleep(2000);
                clear();
            }
        }
        clear();
        board.showPlayerBoard();
    }
    cout << "All ships have been placed." << endl << endl;
    system("pause");
    return board;
}

void showEnding(Board board1, Board board2, Player player1, Player player2)
{
    cout << "You won! - all ships have been sunk!" << endl << endl;
    sleep(2000);
    clear();
    cout << "You won! - all ships have been sunk!" << endl << endl;
    system("pause");
    clear();
    cout << "Player 1:" << endl <<"Max streak: " << player1.getMaxStreak() << "\t Score: " << player1.getScore() << endl << endl << "Board: " << endl << endl;
    board1.showPlayerBoard();
    cout << endl << endl;
    cout << "Player 2:" << endl <<"Max streak: " << player2.getMaxStreak() << "\t Score: " << player2.getScore() << endl << endl << "Board: " << endl << endl;
    board2.showPlayerBoard();
    cout << endl << endl;
}

int main()
{
    string name1="player1";
    string name2="player2";
    char ready = 'N';

    cout << "Enter name of first player: ";
    getline(cin, name1);

    sleep(750);
    clear();

    cout << "Enter name of second player: ";
    getline(cin, name2);

    sleep(750);
    clear();

    Player player1(name1);
    sleep(1500);

    Player player2(name2);
    sleep(1500);

    while (true)
    {
        int answer = showIntro();
        switch(answer)
        {
            case 1:
                showTutorial();
            break;

            case 2:
            break;

            case 3:
                player1.changeName();
            break;

            case 4:
                player2.changeName();
            break;

            case 5:
                clear();
                cout << "Author: Eneasz \"KeneKbee\" Baranowski" << endl << endl;
                system("pause");
                clear();
            break;

            case 6:
                return 0;
            break;
        }
        if (answer == 2)
        {
            break;
        }
        
    }
    
   do
   {
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Are you ready to play a match? Y/N: ";
        cin >> ready;
        clear();
   } while ((toupper(ready) != 'Y'));
   

    while (true)
    {
        Board board1;
        Board board2;

        Ship ships1[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};
        Ship ships2[10] = {4, 3, 3, 2, 2, 2, 1, 1, 1, 1};

        player1.switchPlayer();

        board1.showPlayerBoard();
        board1=placeShips(board1, ships1);

        player2.switchPlayer();

        board2.showPlayerBoard();
        board2=placeShips(board2, ships2);

        clear();
        
        int x;
        int y;
        int streak=0;
        while (true)
        {
            streak=0;

            player1.switchPlayer(); // first player's turn

            while (true) 
            {
                board1.showBothBoards();
                cout << "Streak: " << streak << endl << endl;
                x = getXCoordinate("X");
                y = getYCoordinate("Y");
                if (board2.getChar(x,y)=='-')
                {
                    clear();

                    board1.setCharE(x,y,' ');
                    board2.setCharP(x,y,' ');

                    board1.showBothBoards();
                    cout << "Streak: " << streak << endl << endl;

                    cout << "You missed!" << endl << endl;

                    if (streak >  player1.getMaxStreak())
                    {
                        player1.setMaxStreak(streak);
                    }
                    system("pause");
                    break;
                }
                else if(board2.getChar(x,y)==' ' || board2.getChar(x,y)=='X')
                {
                    cout << "You already shot in that place!" << endl << endl;
                    system("pause");
                }
                else
                {
                    clear();
                    ships2[board2.getChar(x,y)-48].shotsFired(); // 48 is the ASCII value of 0
                    bool sunk = ships2[board2.getChar(x,y)-48].checker();
                    if (sunk == false)
                    {
                        board1.setCharE(x,y,'X');
                        board2.setCharP(x,y,'X');
                    }
                    else {
                        board1.setCharE(x,y,'!');
                        board2.setCharP(x,y,'!');
                    }

                    streak++;

                    board1.showBothBoards();
                    cout << "Streak: " << streak << endl << endl;
                    
                    cout << "You hit a ship!" << endl << endl;
                    
                    if (streak >  player1.getMaxStreak())
                    {
                        player1.setMaxStreak(streak);
                    }

                    if (shipAllChecker(ships2) == false)
                    {
                        if (sunk == true)
                        {
                            cout << "Ship has been sunk!" << endl << endl;
                        }
                    }
                    else {
                        player1.setScore();
                        break;
                    }
                    
                    system("pause");
                }
                clear();
            }
            if (shipAllChecker(ships2) == true)
            {
                break;
            }

            player2.switchPlayer(); // second player's turn

            streak=0;

            while (true) 
            {
                board2.showBothBoards();
                cout << "Streak: " << streak << endl << endl;
                x = getXCoordinate("X");
                y = getYCoordinate("Y");
                if (board1.getChar(x,y)=='-')
                {
                    clear();

                    board2.setCharE(x,y,' ');
                    board1.setCharP(x,y,' ');

                    board2.showBothBoards();
                    cout << "Streak: " << streak << endl << endl;

                    cout << "You missed!" << endl << endl;

                    system("pause");
                    break;
                }
                else if(board1.getChar(x,y)==' ' || board1.getChar(x,y)=='X')
                {
                    cout << "You already shot in that place!" << endl << endl;
                    system("pause");
                }
                else
                {
                    clear();
                    ships1[board1.getChar(x,y)-48].shotsFired(); // 48 is the ASCII value of 0
                    bool sunk = ships1[board1.getChar(x,y)-48].checker();
                    if (sunk == false)
                    {
                        board2.setCharE(x,y,'X');
                        board1.setCharP(x,y,'X');
                    }
                    else {
                        board2.setCharE(x,y,'!');
                        board1.setCharP(x,y,'!');
                    }

                    streak++;

                    board2.showBothBoards();
                    cout << "Streak: " << streak << endl << endl;
                    
                    cout << "You hit a ship!" << endl << endl;

                    if (streak >  player2.getMaxStreak())
                    {
                        player2.setMaxStreak(streak);
                    }

                    if (shipAllChecker(ships1) == false)
                    {
                        if (sunk == true)
                        {
                            cout << "Ship has been sunk!" << endl << endl;
                        }
                    }
                    else {
                        player2.setScore();
                        break;
                    }
                    
                    system("pause");
                }
                clear();
            }
            if (shipAllChecker(ships1) == true)
            {
                break;
            }
        }

        showEnding(board1, board2, player1, player2);

        while (true)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Do you want to play again? Y/N: ";
            cin >> ready;
            clear();
            if (toupper(ready) == 'Y')
            {
                break;
            }
            else if(toupper(ready) == 'N')
            {
                player1.goodbye();
                sleep(1500);
                player2.goodbye();
                sleep(1500);
                cout << endl << "Thanks for playing!" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
}