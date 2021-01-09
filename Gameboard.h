/******************************************************************************
* Class - gameBoard
*
* Description - Manages the board for the TicTacToe game.
*
*
* Member Functions:
*
* gameBoard    - Constructor that initializes blocks and board
* getGameBoard - Returns a char array of the game board
* setBlock     - Places an X or O symbol at position
* isFull       - Checks if the blocks vector is full (X and O)
* updateBoard  - Update values on the board
*
* Member Variables:
*
* blocks - Contains the symbols for the board output
* board  - Contains outline of the TicTacToe board
*
* Exceptions:
*
* symbolInputException - Exception for incorrect symbol input
* blockInputException  - Exception for incorrect array input
*
*****************************************************************************/

#ifndef GAMEBOARD_H

#define GAMEBOARD_H

#define NUM_BLOCKS  9
#define MAX_POS     9
#define MIN_POS     0

#include <string>
#include <iostream>
#include <vector>

class Gameboard
{
public:
	
	Gameboard();

	const char * getGameBoard();

	std::vector< std::string > getBlockList();

	void setBlock(char symbol, short position);

	bool isFull();

	void updateBoard();

	struct blockInputException : public std::exception
	{
		virtual const char * what() const throw ()
		{
			return "Invalid Position - Please enter a number 0 - 8";
		}
	};

private:

	struct occupiedBlockException : public std::exception
	{
		virtual const char * what() const throw ()
		{
			return "Invalid block - Please select unnoccupied block";
		}
	};

	std::vector< std::string > blocks;
	
	std::string board; 

};

#endif // !GAMEBOARD_H