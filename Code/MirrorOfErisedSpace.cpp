/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the MirrorOfErised class. This is 
*	the final room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether to attack, dodge, eat, or quit the
*	fight with Voldemort.
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "MirrorOfErisedSpace.hpp"
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
MirrorOfErised::MirrorOfErised() : Space(Space::MIRROR_OF_ERISED_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
MirrorOfErised::~MirrorOfErised() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int MirrorOfErised::getRoom()
{
	return MIRROR_OF_ERISED_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void MirrorOfErised::printRoomName()
{
	cout << "Harry's Current Location: Mirror Of Erised Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int MirrorOfErised::roomMenu()
{
	cout << "Harry enters the final chamber and looks around. It is a circular\n";
	cout << "room, empty except for a very large, old mirror. Someone is\n";
	cout << "standing in front of the mirror and muttering to themselves. Harry\n";
	cout << "moves closer, trying not to let the person know he is there. All of a\n";
	cout << "sudden the person turns around and Professor Quirrel is staring at \n";
	cout << "Harry! Professor Quirrel? Harry was sure that it had to have been \n";
	cout << "Snape who was working with You-Know-Who. Harry looks into the mirror\n";
	cout << "and sees himself holding the sorcerer stone, which then drops into his\n";
	cout << "pocket just like magic. Voldemort reveals himself and tells Quirrel to\n";
	cout << "kill Harry.\n";
	cout << endl;
	cout << "It is time to fight. You can either attack, dodge, or eat/drink to heal\n";
	cout << endl;

	//Prompt the user to either attack, dodge, or heal
	cout << "Would you like to attack, dodge or heal:\n";
	cout << "1. Attack\n";
	cout << "2. Dodge\n";
	cout << "3. Heal\n";
	cout << "4. Quit Game\n";
	//Validate input
	while (true)
	{
		string intValidation;
		getline(cin, intValidation);
		stringstream ss(intValidation);
		int x;

		if (ss >> x && !(ss >> intValidation) && (x >= 1 && x <= 4))
		{
			return x;
		}
		cin.clear();
		cerr << "Invalid input. Please enter an integer between 1-7: \n";
	}
	
}

/******************************************************************************
*Description: This says that the user selected the correct item necessary to
*	complete the task needed to move on. If the user selects the correct item,
*	then true is returned, otherwise, false is returned.
*****************************************************************************/
bool MirrorOfErised::useCorrectItem(int itemSelection)
{
	return true;
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool MirrorOfErised::taskCompleted()
{
	return true;
}
