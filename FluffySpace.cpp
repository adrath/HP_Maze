/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the Fluffy class. This class 
*	represents the first room of the linked list of rooms. Fluffy, Hagrid's
*	3-headed dog, lives in the room and Harry has to get past him to move to
*	the next room. The class prints a menu for the user to interact with and
*	decide whether they want to look for items in the room, use an item in 
*	the inventory, try and move on to the next room, or quit the game. The 
*	correct item need to move to the next room is kept in the class and the
*	task is accomplished if the correct item is used. Use the flute to advance.
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "FluffySpace.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::cerr;

/******************************************************************************
*Description: The default constructor
*****************************************************************************/
Fluffy::Fluffy() : Space(Space::FLUFFY_ROOM) {}

/******************************************************************************
*Description: The destructor
*****************************************************************************/
Fluffy::~Fluffy() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int Fluffy::getRoom()
{
	return FLUFFY_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void Fluffy::printRoomName()
{
	cout << "Harry's Current Location: Fluffy's Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int Fluffy::roomMenu()
{
	cout << "You have entered the first room, Fluffy's Room. Fluffy is a giant\n";
	cout << "three-headed dog. Hagrid has owned Fluffy since he was just a wee \n";
	cout << "little puppy and has lent him to Professor Dumbldore to guard the \n";
	cout << "sorcerer stone. You must put Fluffy to sleep in order to move past him\n";
	cout << "to get to the stone.\n";
	cout << endl;

	//Menu Selection:
	cout << "What would you like to do: \n";
	cout << "1. Look around the room\n";
	cout << "2. Use item from inventory\n";
	cout << "3. Try and open up the trapdoor\n";
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
bool Fluffy::useCorrectItem(int itemSelection)
{
	if (itemSelection == 0)
	{
		task = true;
		return true;
		cout << "Harry begins to play the flute... He is terrible at it but\n";
		cout << "Fluffy begins to fall asleep.\n";
	}
	else
	{
		cout << "This is not the correct item.\n";
		cout << "Hint: Hagrid used to sing him to sleep every night.\n";
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool Fluffy::taskCompleted()
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