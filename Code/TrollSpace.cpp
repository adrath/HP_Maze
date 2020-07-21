/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description:  This is the source code for the Troll class. This is 
*	the fifth room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used. There is no correct
*	item to use for this class. Just walk to the next room to advance.
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "TrollSpace.hpp"
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
Troll::Troll() : Space(Space::TROLL_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
Troll::~Troll() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int Troll::getRoom()
{
	return TROLL_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void Troll::printRoomName()
{
	cout << "Harry's Current Location: Troll Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int Troll::roomMenu()
{
	cout << "You and Hermionie leave Ron alone, hurt and unconsious... Great friends\n";
	cout << "you are. You move on to the next room where an awful stench reaches your \n";
	cout << "nose. You look around and see a 20' tall mountain troll! But for some \n";
	cout << "reasonit is laying very still. You decide to inch closer to it and see \n";
	cout << "that it has been stunned. Maybe you two should run through the room quickly\n"; 
	cout << "before it wakes up.\n";
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
bool Troll::useCorrectItem(int itemSelection)
{
	cout << "You don't need an item. Get out of the room as fast as possible!\n";
	cout << " This smell is awful!\n";
	return false;
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool Troll::taskCompleted()
{
	return true;
}
