#include "gameBoard.h"

Gameboard::Gameboard()
{
	// Fill in a space for each block
	for (int i = 0; i < NUM_BLOCKS; i++)
	{
		blocks.push_back(" ");
	}

	updateBoard();
}

// Set either an X or an O on the gameBoard
void Gameboard::setBlock(char symbol, short position)
{
	// Sanitize position input
	if ( position < MIN_POS || position >= MAX_POS )
	{
		throw blockInputException();
	}

	// Make sure to not override space
	if ( blocks[position] != " " )
	{
		throw occupiedBlockException();
	}

	blocks[position] = symbol;

	updateBoard();
}

// Check if the board vector is full
bool Gameboard::isFull()
{
	int size = 0;
	for (int i = 0; i < MAX_POS; i++)
	{
		if(blocks[ i ] != " ") { size++; }
	}

	return ( size == MAX_POS );
}

// Update values on the board
void Gameboard::updateBoard()
{
	// Fill the board with values from blocks
	board = "\r " + blocks[0] + " | " + blocks[1] + " | " + blocks[2] + "  \n" +
		    "\r------------\n" +
		    "\r " + blocks[3] + " | " + blocks[4] + " | " + blocks[5] + "  \n" +
	     	"\r------------\n" +
		    "\r " + blocks[6] + " | " + blocks[7] + " | " + blocks[8] + "  \n";
}

// Retreive a char array of the game board
const char * Gameboard::getGameBoard()
{
	return board.c_str();
}

// Return a vector of the block list
std::vector<std::string> Gameboard::getBlockList()
{
	return blocks;
}
