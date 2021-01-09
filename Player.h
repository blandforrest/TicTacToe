/******************************************************************************
* Class - Player
*
* Description - This class holds components for the player which includes
*               position values
*
* Member Functions -
*
* Player - Creates a player object given the symbol, type, and board ptr
* getSymbol - Returns the character being used by the Player
* determineMove - Either prompts a player for input or makes the Bot move
* handleInput - Handles a string from input to try and parse to a short
*
*
* Member Variables -
*
* playerSymbol - Holds the symbol the player draws to the board
* playerType - Enum that represents if the player is a human or bot
* boardReference - A shared_ptr that references the Gameboard
*
*****************************************************************************/

#ifndef PLAYER_H

#define PLAYER_H

#include <iostream>
#include <exception>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include <string>

#include "Gameboard.h"

enum playerEnum { HUMAN = 0, BOT = 1 };

class Player
{
public:

	Player();
	
	Player( char playerSymbol, int playerType, std::shared_ptr< Gameboard > board );

	char getSymbol();

	void determineMove();

	short getPlayerType();

	short handleInput( std::string userInput );

private:

	struct symbolInputException : public std::exception
	{
		virtual const char * what() const throw ()
		{
			return "Invalid Symbol - Please enter X or O";
		}
	};

	void determinePlayerMove();
	void determineBotMove();

	char playerSymbol;
	int playerType;
	std::shared_ptr< Gameboard > boardReference;
};

#endif // !PLAYER_H