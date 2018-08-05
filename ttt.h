#include<iostream>
#include<exception>
#include<time.h>
#include<stdlib.h>

class TicTacToe{
public:
  void Display(); //Prints the table
  void help_Menu(); //Displays information for the user
  void select_Sym(); //Prompts user to select symbol
  void select_first(); //Randomly chooses whether the person or computer goes first
  void select_box(); //User selects box to place Value box must be from 0 - 1 and unoccupied
  void check_win(char x);
  void start();
  void comp_select(); //Computer chooses place to enter symbol
private:
  char usr_symbol, comp_symbol, first;
  char board[9] = "";
  bool occupied[9] = {false};

};


struct Input_Exception : public std::exception {
   const char * what () const throw () {
      return "Invalid Input - Please enter X or O";
   }
};

struct Invalid_Block_Exception : public std::exception {
   const char * what () const throw () {
      return "Invalid block number - Please enter a number 0 - 8";
   }
};

struct Occupied_Block_Exception : public std::exception {
   const char * what () const throw () {
      return "Invalid block - Please select unnoccupied block";
   }
};
