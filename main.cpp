#include "TicTacToe.h"


int main()
{
	std::unique_ptr< TicTacToe > newGame( new TicTacToe );

	newGame->gameStart();

	return 0;
}