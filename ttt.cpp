#include "ttt.h"

TicTacToe new_game;

int main(){
  new_game.start();
  return 0;
}

void TicTacToe::start(){
  std::string input;
  std::cout << "If you do not understand how to play - type: help, otherwise, press enter to continue" << std::endl;
  std::cin >> input;

  if(input == "help"){new_game.help_Menu();}
  new_game.select_Sym();
  new_game.select_first();


  if(first == 'C'){
    while(1){
      comp_select();
      Display();
      check_win(comp_symbol);
      select_box();
      Display();
      check_win(usr_symbol);
    }
  }
  else{
    while(1){
      select_box();
      Display();
      check_win(usr_symbol);
      comp_select();
      Display();
      check_win(comp_symbol);
    }
  }
}

void TicTacToe::help_Menu(){
  std::cout << "First, select your symbol(Either X or O)" << std::endl <<
  "Next, a coin will be flipped with the computer to see who will go first" << std::endl <<
  "After this, you may place a symbol in the table by using numbers 0 - 8 to place your symbol" << std::endl <<
  "This starts at the top left and moves to the right." << std::endl <<
  "You may not replace an existing symbol" << std::endl << std::endl;
  std::cout << "  " << 0 << "  |  " << 1 <<"  |  " << 2 << "  " << std::endl <<
               "- - - - - - - - -" << std::endl <<
               "  " << 3 << "  |  " << 4 <<"  |  " << 5 << "  " << std::endl <<
               "- - - - - - - - -" << std::endl <<
               "  " << 6 << "  |  " << 7 <<"  |  " << 8 << "  " << std::endl;
}

void TicTacToe::Display(){
  std::cout << std::endl << std::endl;
  std::cout << "  " << board[0] << "  |  " << board[1] <<"  |  " << board[2] << "  " << std::endl <<
               "- - - - - - - - -" << std::endl <<
               "  " << board[3] << "  |  " << board[4] <<"  |  " << board[5] << "  " << std::endl <<
               "- - - - - - - - -" << std::endl <<
               "  " << board[6] << "  |  " << board[7] <<"  |  " << board[8] << "  " << std::endl;
  std::cout << std::endl;
}

void TicTacToe::select_Sym(){
  while(1){
    try{
      std::cout << "Select symbol: ";
      std::cin >> usr_symbol;
      if(usr_symbol != 'X' && usr_symbol != 'x' && usr_symbol != 'O' && usr_symbol != 'o'){
        throw Input_Exception();
      }
      break;
    }
    catch(Input_Exception e){
        std::cout << e.what() << std::endl;
    }
  }
  if(usr_symbol == 'X' || usr_symbol == 'x'){
    comp_symbol = 'O';
  }
  else{
    comp_symbol = 'X';
  }
}

void TicTacToe::select_first(){
  srand(time(NULL));
  int i = rand() % 2;
  if(i == 0){
    first = 'C';
    std::cout << "The computer will go first" << std::endl;
    }
  else{
    first = 'U';
    std::cout << "You will go first" << std::endl;
  }
}

void TicTacToe::select_box(){
  int block_num;
  while(1){ //Input validation
    try{
      std::cout << "Enter block to enter: ";
      std::cin >> block_num;
      std::cout << std::endl;
      if(block_num < 0 || block_num > 8){
        throw Invalid_Block_Exception();
      }
      if(occupied[block_num] == true){
        throw Occupied_Block_Exception();
      }
      break;
    }
    catch(Invalid_Block_Exception e){
      std::cout << e.what() << std::endl;
    }
    catch(Occupied_Block_Exception e){
      std::cout << e.what() << std::endl;
    }
  }
  board[block_num] = usr_symbol;
  occupied[block_num] = true;
}

void TicTacToe::check_win(char x){
  //Checks for winning combination
  if( (board[0] == x && board[4] == x && board[8] == x) || (board[2] == x && board[4] == x && board[6] == x) ||
      (board[0] == x && board[1] == x && board[2] == x) || (board[2] == x && board[5] == x && board[8] == x) ||
      (board[0] == x && board[3] == x && board[6] == x) || (board[6] == x && board[7] == x && board[8] == x)){
        std::cout << "*-----------------------*" << std::endl <<
                     "*       "<<x<<" WINS          *" << std::endl <<
                     "*-----------------------*" << std::endl;
        std::exit(0);
      }
    for(int i = 0; i < 9; i++){
      if(occupied[i] == false){return;}
    }
    std::cout << "*-----------------------*" << std::endl <<
                 "*      IT'S A TIE!      *" << std::endl <<
                 "*-----------------------*" << std::endl;
    std::exit(0);
}

void TicTacToe::comp_select(){
  srand(time(NULL));
  int i = rand() % 9;

  if(occupied[i] == true){
    while(1){
      i = rand() % 9;
      if(occupied[i] == false){
        break;
      }
    }
  }
  board[i] = comp_symbol;
  occupied[i] = true;
}
