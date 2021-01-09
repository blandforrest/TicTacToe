/******************************************************************************
* Class - TicTacToe
*
* Description - Contains the functions to play TicTacToe, begins with the start
*               function
*
* Member Functions:
*
* TicTacToe    - Creates the game board
* ~TicTacToe   - Destroys game board and players
* gameStart    - Calls the startMenu and gameLoop functions
* gameLoop     - Cycles through selecting board spaces and checking for winners
* gamePrintln  - Utility function to easily print with a newline
* startMenu    - Starts the game with a menu and creates the player objects
* checkWinner  - Checks for winners and returns the winner value
* handleWinner - Takes the winner value and generates output
* determinePlayerStart - Randomly picks a player to start
*
*
* Member Variables -
*
* playerWins - Message for if the player wins
* playerLoses - Message for if the player loses
* playerTie - Message for if there is a tie
* human - Player object for human input
* bot - Player object for bot input
* gameBoard - Gameboard object for saving positions
*
*****************************************************************************/

#ifndef TICTACTOE_H

#define TICTACTOE_H

#define NO_WINNER -1
#define TIE       -2

#include <exception>

#include "Gameboard.h"
#include "Player.h"

class TicTacToe
{
public:
    
    TicTacToe();

    ~TicTacToe();

    void gameStart();

    void gameLoop();

    void gamePrintln(const char * str);

    void startMenu();

    int checkWinner( std::shared_ptr< Gameboard > boardReference, std::shared_ptr< Player > playerReference );

    void handleWinner( short winType );

    unsigned short int determinePlayerStart();


private:    

    const char * playerWins =  "-----------------------------------"
                               "|           Player WINS           |"
                               "-----------------------------------";

    const char * playerLoses = "-----------------------------------"
                               "|           Player LOSES          |"
                               "-----------------------------------";

    const char * playerTie =   "-----------------------------------"
                               "|               TIE               |"
                               "-----------------------------------";

    std::shared_ptr< Player >   human, bot;
    std::shared_ptr< Gameboard > gameBoard;
};

#endif // !TICTACTOE_H
