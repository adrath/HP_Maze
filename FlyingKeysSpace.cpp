/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the FlyingKey class. This is 
*	the third room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used. Use the broomstick
*	to advance.
******************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "FlyingKeysSpace.hpp"
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
FlyingKeys::FlyingKeys() : Space(Space::FLYING_KEYS_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
FlyingKeys::~FlyingKeys() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int FlyingKeys::getRoom()
{
	return FLYING_KEYS_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void FlyingKeys::printRoomName()
{
	cout << "Harry's Current Location: Flying Keys Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int FlyingKeys::roomMenu()
{
	cout << "You entire a room with a strange buzzing sounds overhead.\n";
	cout << "You look up and see hundreds of flying winged keys. The door\n";
	cout << "on the other side of the room is closed and looks solidly locked.\n";
	cout << "You attempt to open the door with a spell but it doesn't work.\n";
	cout << "You know what you have to do... you gotta catch that key. But how...\n";
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
*	then true is returned, otherwise, false is returned. They have a 40% chance
*	of getting the correct key each time it is correctly entered.
*****************************************************************************/
bool FlyingKeys::useCorrectItem(int itemSelection)
{
	if (itemSelection == 2)
	{
		int randNum = rand() % 10;
		if (randNum == 1 || randNum == 2)
		{
			cout << "You caught the key! You insert it into the door and hear a satisfying click\n";
			task = true;
			return true;
		}
		else
		{
			cout << "You caught a key but it was the wrong one... Better try again\n";
			return false;
		}
	}
	else
	{
		cout << "That isn't the correct item\n";
		cout << "Hint: You are the youngest seeker in a century!\n";
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool FlyingKeys::taskCompleted()
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