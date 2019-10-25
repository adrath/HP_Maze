/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the PotionChallenge class. This is 
*	the sixth room in the linked list. The class prints a menu for the user 
*	to interact with and decide which potion they would like to drink. The 
*	user chooses based off of the riddle displayed in the roomMenu() function.
*	The selection is returned to the Menu class then places the bottle in 
*	harry's inventory before calling it and drinking it. If Harry chose the
*	correct bottle then he will have completed the task. The contents of each
*	bottle is:
*		1. Poison
*		2. Nettle Wine
*		3. Move on to next room potion (Correct Potion)
*		4. Poison
*		5. Poison
*		6. Nettle Wine
*		7. Go back the way you came potion
*****************************************************************************/
#include <iostream>
#include <string>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "PotionChallengeSpace.hpp"
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
PotionChallenge::PotionChallenge() : Space(Space::POTIONS_ROOM) {}

/******************************************************************************
**Description: The destructor
*****************************************************************************/
PotionChallenge::~PotionChallenge() {}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int PotionChallenge::getRoom()
{
	return POTIONS_ROOM;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void PotionChallenge::printRoomName()
{
	cout << "Harry's Current Location: Potion's Room\n";
}

/******************************************************************************
*Description: This function prints what is happening in the room and the options
*	 that the user has for interacting with the game. It then returns the user
*	 selection and performs that action in the Menu Class.
*****************************************************************************/
int PotionChallenge::roomMenu()
{
	//Print description, picture of the table, and logic problem (quote/example
	//  pulled directly from Harry Potter and the Sorcerer Stone book)
	cout << "You made it into a square room with a table in the middle of it.\n";
	cout << "The instant you and Hermionie step through the door, flames appear\n";
	cout << "blocking the entrance and exit. You walk up to the table and see an\n";
	cout << "assortment of different sized bottles full of liquid.\n";
	cout << endl;
	cout << "Table: \n";
	cout << "********************************************************************\n";
	cout << "*                                                  ___             *\n";
	cout << "*                                                 _| |_            *\n";
	cout << "*                              ___               /     \\           *\n";
	cout << "*            ___             __| |__     ___     |     |      _    *\n";
	cout << "*   ___     _| |_            |     |     | |     |     |     / \\   *\n";
	cout << "*  _| |_   /     \\    ___    |     |     | |     |     |    _| |_  *\n";
	cout << "* /     \\  |     |   _| |_   |     |    _| |_    |     |   /     \\ *\n";
	cout << "* |     |  |     |  /     \\  |     |   /     \\   |     |   |     | *\n";
	cout << "* |_____|  |_____|  \\_____/  |_____|   \\_____/   |_____|   |_____| *\n";
	cout << "*    1        2        3        4         5         6         7    *\n";
	cout << "********************************************************************\n";
	cout << endl;
	cout << "Also on the table a scroll of parchment with instructions that reads:\n";
	cout << endl;
	cout << "       Danger lies before you, while safety lies behind,\n";
	cout << "       Two of us will help you, whichever you would find,\n";
	cout << "          One among us seven will let you move ahead,\n";
	cout << "        Another will transport the drinker back instead,\n";
	cout << "          Two among our number hold only nettle wine,\n";
	cout << "       Three of us are killers, waiting hidden in line.\n";
	cout << "      Choose, unless you wish to stay here for evermore,\n";
	cout << "   To help you in your choice, we give you these clues four:\n";
	cout << "        First, however slyly the poison tries to hide\n";
	cout << "     You will always find some on nettle wine’s left side;\n";
	cout << "      Second, different are those who stand at either end,\n";
	cout << "     But if you would move onwards, neither is your friend;\n";
	cout << "       Third, as you see clearly, all are different size,\n";
	cout << "     Neither dwarf nor giant holds death in their insides;\n";
	cout << "      Fourth, the second left and the second on the right\n";
	cout <<	"  Are twins once you taste them, though different at first sight.\n";
	cout << endl;
	cout << "                      ~Severus Snape\n";
	cout << endl;
	cout << endl;

	//Prompt the user to pick which bottle they would like to drink from
	cout << "Which potion would you like to pick: ";
	//Validate input
	while (true)
	{
		string intValidation;
		getline(cin, intValidation);
		stringstream ss(intValidation);
		int x;

		if (ss >> x && !(ss >> intValidation) && (x >= 1 && x <= 7))
		{
			select = x;
			return select;
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
bool PotionChallenge::useCorrectItem(int itemSelection)
{
	if (itemSelection == 4)
	{
		task = true;
		return true;
	}
	else
	{
		cout << "This is not the correct item.\n";
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool PotionChallenge::taskCompleted()
{
	return true;
}