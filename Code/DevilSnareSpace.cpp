/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the DevilSnare class. This is 
*	the second room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used. Use the wand to
*	advance.
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "DevilSnareSpace.hpp"
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
DevilSnare::DevilSnare() : Space(Space::DEVIL_SNARE_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
DevilSnare::~DevilSnare() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int DevilSnare::getRoom()
{
	return DEVIL_SNARE_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void DevilSnare::printRoomName()
{
	cout << "Harry's Current Location: Devil Snare Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int DevilSnare::roomMenu()
{
	cout << "Fluffy woke up as you were going through the trap door! You\n";
	cout << "won't be able to go back that way now. When you jump down the\n";
	cout << "trap door you land on something very squishy. As you try and \n";
	cout << "figure out what you land on, you notice that you can't move \n";
	cout << "you legs. You realize that a plant is starting quickly tighten\n";
	cout << "around you, trying to stangle you! The plant's name is Devil Snare.\n";
	cout << "Devil Snare loves dark, cold places and can't stand sunlight. \n";
	cout << "You must act fast! Every second you waste, the stronger the plant's\n";
	cout << "hold strengthens on you.\n";
	cout << endl;
	
	//Menu Selection:
	cout << "What would you like to do: \n";
	cout << "1. Look around the room\n";
	cout << "2. Use item from inventory\n";
	cout << "3. Try worm your way out\n";
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
bool DevilSnare::useCorrectItem(int itemSelection)
{
	if (itemSelection == 1)
	{
		cout << "Lumos Maximus!\n";
		cout << "A blinding flash of bright white light comes from the tip of your wand.\n";
		cout << "The Devil Snare releases you.\n";
		task = true;
		return true;
	}
	else
	{
		cout << "Nope, that isn't the correct item!\n";
		cout << "Hint: Maybe you know a spell that could produce sunlight?\n";
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool DevilSnare::taskCompleted()
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
