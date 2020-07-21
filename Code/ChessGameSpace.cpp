/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the ChessGame class. This is 
*	the forth room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used. Use the chess 
*	piece to advance.
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "ChessGameSpace.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::cerr;

/******************************************************************************
**Description: The default constructor
*****************************************************************************/
ChessGame::ChessGame() : Space(Space::CHESS_GAME_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
ChessGame::~ChessGame() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int ChessGame::getRoom()
{
	return CHESS_GAME_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void ChessGame::printRoomName()
{
	cout << "Harry's Current Location: Chess Game Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int ChessGame::roomMenu()
{
	cout << "You enter the next room and see a giant Chess board. You have been\n";
	cout << "learning to play wizards chess from Ron. Maybe you should play your way\n";
	cout << "across the board. If only we had that missing chess piece\n";
	cout << endl;

	//Menu Selection:
	cout << "What would you like to do: \n";
	cout << "1. Look around the room\n";
	cout << "2. Use item from inventory\n";
	cout << "3. Try and open up the next door\n";
	cout << "4. Run away and quit the game\n";

	//Validate input
	while (true)
	{
		string intValidation;
		getline(cin, intValidation);
		stringstream ss(intValidation);
		int x;

		if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2 || x == 3 || x == 4))
		{
			return x;
		}
		cin.clear();
		cerr << "Invalid input. Please enter 1, 2, 3, or 4: \n";
	}
}

/******************************************************************************
*Description: This says that the user selected the correct item necessary to
*	complete the task needed to move on. If the user selects the correct item,
*	then true is returned, otherwise, false is returned.
*****************************************************************************/
bool ChessGame::useCorrectItem(int itemSelection)
{
	if (itemSelection == 3)
	{
		cout << "You place the missing piece on the board and begin to play.\n";
		cout << "Ron is a Knight, Hermionie is a castle, and Harry is a bishop.\n";
		cout << "Knight to H3... Check\n";
		cout << "Queen to H3.\n";
		cout << "Ron has been knocked unconscious by the Queen.\n";
		cout << "Harry moves to E5\n";
		cout << "Checkmate!\n";
		task = true;
		return true;
	}
	else
	{
		cout << "This is not the correct item.\n";
		cout << "Hint: Maybe you left a chess piece in your pocket.\n";
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool ChessGame::taskCompleted()
{
	if (task) 
	{
		return true;
	}
	else
	{
		return false;
	}
}
