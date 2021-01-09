#include "TicTacToe.h"

// Create the game board
TicTacToe::TicTacToe()
{
    gameBoard = std::shared_ptr< Gameboard > ( new Gameboard() );
    human = NULL;
    bot = NULL;
}

// Clean up objects
TicTacToe::~TicTacToe() {}

// Call the menu and loop
void TicTacToe::gameStart()
{  
    startMenu();

    gameLoop();
}

// Print strings with newlines
void TicTacToe::gamePrintln(const char* str)
{
    std::cout << str << std::endl;
}

// Get input and check for winner
void TicTacToe::gameLoop()
{
    bool gameEnded = false;

    bool playerTurn = ( bool ) determinePlayerStart();

    // Main loop for game
    while (!gameEnded)
    {
        std::shared_ptr< Player > playerRef = ( playerTurn ? human : bot );
        
        gamePrintln(gameBoard->getGameBoard());

        playerRef->determineMove();

        short winner = checkWinner(gameBoard, playerRef);
        
        if ( winner != NO_WINNER )
        {
            handleWinner( winner );

            gamePrintln( gameBoard->getGameBoard() );
            
            gameEnded = true;
        }

        playerTurn = !playerTurn;
    }
}

// Prompt the user with a start menu
void TicTacToe::startMenu()
{
    bool menuCompleted = false;
    char usrSymbol, botSymbol;

    gamePrintln("----- Welcome to TicTacToe -----");

    while (!menuCompleted)
    {
        gamePrintln("Select 'X' or 'O'");

        std::cin >> usrSymbol;

        try
        {
            human = std::unique_ptr< Player > ( new Player( usrSymbol, playerEnum::HUMAN, gameBoard ) );

            botSymbol = ( human->getSymbol() == 'X' ) ? 'O' : 'X';

            bot = std::unique_ptr< Player > ( new Player(botSymbol, playerEnum::BOT, gameBoard  ) );
        }

        catch (std::exception &e)
        {
            gamePrintln( e.what() );

            continue;
        }

        menuCompleted = true;
    }
}

// Determine the player to go first
unsigned short int TicTacToe::determinePlayerStart()
{
  srand( time( NULL ) );
  
  return ( rand() % 2 );  
}

// Checks the gameBoard for a winning combination
int TicTacToe::checkWinner( std::shared_ptr< Gameboard > boardReference, std::shared_ptr< Player > playerReference )
{
    std::vector<std::string> board = boardReference->getBlockList();
     
    short winner = NO_WINNER;
    std::string playerChar(1, playerReference->getSymbol() );
    bool playerWins = false;
    
    std::vector< std::vector< short > > playerWinPos = {{0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // Rows
                                                        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, // Cols
                                                        {0, 4, 8}, {2, 4, 6}};           // Diag
    for ( auto & vec : playerWinPos )
    {
        short hitCount = 0;
        for (auto & num : vec)
        {          
            if (board[num] == playerChar)
            {
                hitCount++;
            }
        }
        if (hitCount == 3)
        {
            winner = playerReference->getPlayerType();
        }
    }

    if ( boardReference->isFull() )
    {
        winner = TIE;
    }

    return winner;
}

// Displays victory message after win
void TicTacToe::handleWinner( short winType )
{
    const char * winMessage = NULL;

    switch( winType )
    {
        case playerEnum::BOT:
            winMessage = playerLoses;
            break;

        case playerEnum::HUMAN:
            winMessage = playerWins;
            break;

        case TIE:
            winMessage = playerTie;
    }

    gamePrintln( winMessage );
}
