#include "Player.h"

// Constructor for the Players
Player::Player( char symbol, int ptype, std::shared_ptr< Gameboard > board )
{
	char upperSymbol = toupper(symbol);

	// Symbol can only be X or O
	if ( upperSymbol != 'X' && upperSymbol != 'O' )
	{
		throw symbolInputException();
	}

	playerSymbol = upperSymbol;
	playerType = ptype;
	boardReference = board;
}

// Ask the player where to insert the symbol
void Player::determinePlayerMove()
{
	std::string stringInput;
	short playerInput;
	bool inputSuccessful = false;
	
	while (!inputSuccessful)
	{
		std::cout << "Enter the desired location ( 0 - 8 ): ";

		try
		{
			std::cin >> stringInput;
			playerInput = handleInput(stringInput);

			boardReference->setBlock( getSymbol(), playerInput );
		}
		catch ( std::exception &e )
		{
			std::cout << e.what() << std::endl;

			continue;
		}

		inputSuccessful = true;

	}
	std::cout << std::endl;

}

// Generate a position for the BOT
void Player::determineBotMove()
{
	typedef unsigned short uShort;

	std::vector< std::string > blockList = boardReference->getBlockList();
	std::vector< uShort > freeBlockList;

	srand( time( NULL ) );

	// Determine free spaces within string
	for ( uShort i = 0; i < blockList.size(); i++ )
	{
		if ( blockList[ i ] == " ") { freeBlockList.push_back(i); }
	}

	uShort rndIdx = rand() % freeBlockList.size();

	// Try to set the block with the random index
	try
	{
		boardReference->setBlock( playerSymbol, freeBlockList[ rndIdx ] );
	}
	catch( std::exception &e )
	{
		std::cout << e.what() << std::endl;
	}
}

// Call the function based on playerType
void Player::determineMove()
{
	(playerType == HUMAN) ? determinePlayerMove() : determineBotMove();
}

// Return the symbol X or O
char Player::getSymbol()
{
	return playerSymbol;
}

// Return either HUMAN or BOT
short Player::getPlayerType()
{
	return playerType;
}

// Attempt to parse the string to integer
short Player::handleInput( std::string userInput )
{
	try
	{
		return ( std::stoi( userInput ) );
	}
	catch ( std::exception &e )
	{
		throw Gameboard::blockInputException();
	}
}
