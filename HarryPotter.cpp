/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the source code for the HarryPotter class. This class
*	functions as the Harry Potter character used in the game. When the 
*	constructor is called, the health and damage is initialized, along with
*	adding items into the "inventory". The inventory is a deque container that
*	will store up to 10 items in it. This class defines how to add and remove
*	items from the inventory. It also keeps track of where Harry is located at
*	and also prints out a map for the user to look at.
*****************************************************************************/
#include <iostream>
#include <deque>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "HarryPotter.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::cerr;
using std::deque;

/******************************************************************************
 *Description: The constructor for the HarryPotter class. The health and damage
 *	are initialized. There are items that are also placed in to the inventory.
 *****************************************************************************/
HarryPotter::HarryPotter()
{
	health = 100;
	damage = 0;
	inventory.push_back(FLUTE);
	inventory.push_back(WAND);
	inventory.push_back(BROOMSTICK);
	inventory.push_back(CHESS_PIECE);
	inventory.push_back(CHOCOLATE_FROGS);
	inventory.push_back(CAULDRON_CAKES);
}

/******************************************************************************
*Description: The destructor for the HarryPotter class. If there is anything in
*	the inventory, it is popped off and discarded.
*****************************************************************************/
HarryPotter::~HarryPotter()
{
	while (!inventory.empty())
	{
		inventory.pop_front();
	}
}

/******************************************************************************
*Description: sets the current location of Harry by passing in an integer 
*	value and that integer value corresponds to the Location enum list 
*	from Space class.
*****************************************************************************/
void HarryPotter::setCurrentLocation(int place)
{
	currentLocation = place;
}

/******************************************************************************
*Description: returns the current location of Harry by returning an integer 
*	value that corresponds to the Location enum list from Space class.
*****************************************************************************/
int HarryPotter::getCurrentLocation()
{
	return currentLocation;
}

/******************************************************************************
*Description: Displays the current inventory that Harry currently.
*****************************************************************************/
void HarryPotter::displayInventory()
{
	int i = 1;
	deque<Items> temp = inventory;
	cout << "\nHarry's Current Inventory:\n";
	while (!temp.empty())
	{
		cout << i << ". ";

		switch (temp.front())
		{
		case FLUTE:
			cout << "Hagrid's Flute\n";
			break;
		case WAND:
			cout << "Harry's Wand\n";
			break;
		case BROOMSTICK:
			cout << "Flying Broomstick\n";
			break;
		case CHESS_PIECE:
			cout << "Chess Pieces\n";
			break;
		case SNAPES_POTION:
			cout << "Snape's Potion\n";
			break;
		case BUTTER_BEER:
			cout << "Foaming pint of Butter Beer (Heal +15)\n";
			break;
		case FIRE_WHISKEY:
			cout << "Straight shot of Fire Whiskey (Heal +20)\n";
			break;
		case MEAD:
			cout << "Pint of Mead (Heal +10)\n";
			break;
		case CHOCOLATE_FROGS:
			cout << "Chocolate Frog (Heal +10)\n";
			break;
		case BBEFB:
			cout << "Bertie Bott's Every Flavor Beans (Heal unknown)\n";
			break;
		case COCKROACH_CLUSTER:
			cout << "Cockroach Cluster (Heal +5)\n";
			break;
		case CAULDRON_CAKES:
			cout << "Cauldron Cakes (Heal +15)\n";
			break;
		}

		temp.pop_front();
		i++;
	}
	cout << "What item would you like to select?\n";
}

/******************************************************************************
*Description: Returns the size of the inventory.
*****************************************************************************/
int HarryPotter::getInventorySize()
{
	return inventory.size();
}

/******************************************************************************
*Description: Places a new item into Harry’s inventory at the end of the deque.
*****************************************************************************/
void HarryPotter::placeItemInInventory(int item)
{
	if (inventory.size() < 10)
	{
		if (item == BUTTER_BEER)
		{
			inventory.push_back(BUTTER_BEER);
		}
		if (item == FIRE_WHISKEY)
		{
			inventory.push_back(FIRE_WHISKEY);
		}
		if (item == MEAD)
		{
			inventory.push_back(MEAD);
		}
		if (item == CHOCOLATE_FROGS)
		{
			inventory.push_back(CHOCOLATE_FROGS);
		}
		if (item == BBEFB)
		{
			inventory.push_back(BBEFB);
		}
		if (item == COCKROACH_CLUSTER)
		{
			inventory.push_back(COCKROACH_CLUSTER);
		}
		if (item == CAULDRON_CAKES)
		{
			inventory.push_back(CAULDRON_CAKES);
		}
		if (item == SNAPES_POTION)
			inventory.push_back(SNAPES_POTION);
	}
	else
	{
		cout << "Not enough room in your pockets to carry this item.\n";
	}
}

/******************************************************************************
*Description: This function is used for when Harry wants to use an item. The 
*	displayInventory() function is called to supply a list of what items Harry 
*	currently has in his inventory. The user then selects said item and the 
*	resulting enum value is then returned. If it is either a potion, drink, 
*	or food, it is removed from the inventory.
*****************************************************************************/
int HarryPotter::useItem()
{
	displayInventory();
	while (true)
	{
		string intValidation;
		getline(cin, intValidation);
		stringstream ss(intValidation);
		int x;
		if (ss >> x && !(ss >> intValidation) && (x <= inventory.size()) && (x > 0))
		{
			if (x <= 4)
			{
				return x;
			}
			else
			{
				int selection = inventory.at(x-1);
				inventory.erase(inventory.begin()+(x-1));
				return selection;
			}
		}
		cin.clear();
		cerr << "Invalid input. Please enter 1 or 2: \n";
	}
}

/******************************************************************************
*Description: This function uses is called when Harry is in the potion room and
*	is selecting what potion he would like to drink.
*****************************************************************************/
void HarryPotter::useSnapesPotion(int potionNum)
{
	inventory.pop_back();
	if (potionNum == 3)
	{
		cout << "You have selected the correct potion!\n";
	}
	else if (potionNum == 7)
	{
		cout << "This potion will send the user back the way you came... better\n";
		cout << "leave this one for Hermionie to use\n";
	}
	else if (potionNum == 2 || potionNum == 6)
	{
		cout << "Drank the potion and didn't die... maybe I should try and walk \n";
		cout << "through the fire...\n";
		cout << "*instantly burns toe off*\n";
		takeDamage(40);
		cout << "Guess that was just the nettle wine...";
	}
	else
	{
		cout << "The world goes dark and you died... maybe Harry should brush\n";
		cout << "up on his logic skills.\n";
		health -= 10000;
	}
}

/******************************************************************************
*Description: This function takes damage and deducts the remaining health 
*	that Harry has.
*****************************************************************************/
void HarryPotter::healDamage(int heal)
{
	if (heal == BUTTER_BEER)
	{
		cout << "Cheers!\n";
		health += 15;
	}
	else if (heal == FIRE_WHISKEY)
	{
		cout << "Every part of my body feels invigorated\n";
		health += 20;
	}
	else if (heal == MEAD)
	{
		cout << "I really meaded that...\n";
		health += 10;
	}
	else if (heal == CHOCOLATE_FROGS)
	{
		cout << "I think it is still jumping up in down in my stomach!\n";
		health += 10;
	}
	else if (heal == BBEFB)
	{
		int randomInt = rand() % 4;
		if (randomInt == 1)
		{
			cout << "Boggie flavored beans? Eww!\n";
			health += -5;
		}
		else
		{
			cout << "Peppermint? Yumm!\n";

			health += (rand() % 11);
		}
	}
	else if (heal == COCKROACH_CLUSTER)
	{
		cout << "Why would you make me eat this?\n";
		health += 5;
	}
	else if (heal == CAULDRON_CAKES)
	{
		cout << "Mmmm...Caaake...\n";
		health += 15;
	}
	else
	{
		health += 0;
	}
		
}

/******************************************************************************
*Description: Takes the damage passed to it and subtracts that from Harry's 
*	health.
*****************************************************************************/
void HarryPotter::takeDamage(int dam)
{
	cout << "Ouch!\n";
	health -= dam;
}

/******************************************************************************
*Description: returns Harry’s current health.
*****************************************************************************/
int HarryPotter::getHealth()
{
	return health;
}

/******************************************************************************
*Description: takes the damage passed to it and subtracts that from Voldemort's
*	health.
*****************************************************************************/
void HarryPotter::attackVoldemort(int attack)
{
	voldemort -= attack;
}

/******************************************************************************
* Description: returns Voldemort's current health.
*****************************************************************************/
int HarryPotter::getVoldemortHealth()
{
	return voldemort;
}

/******************************************************************************
*Description: prints a map of where Harry Potter is currently located.
*****************************************************************************/
void HarryPotter::printMap()
{
	cout << "I solemnly swear that I am up to no good.\n";
	cout << endl;
	cout << "**********\n";
	cout << "*Fluffy's*\n";
	cout << "*        *\n";
	cout << "* Room   *\n";
	cout << "**********\n";
	cout << "    |" << endl;
	cout << "    V" << endl;
	cout << "********    *******   ********\n";
	cout << "*Devil *    *Troll*   *Potion*\n";
	cout << "*Snare *    *Room *   * Room *\n";
	cout << "*Room  *    *     *-->*      *\n";
	cout << "*      *    *     *   *      *\n";
	cout << "*      *    *     *   *      *\n";
	cout << "********    *******   ********\n";
	cout << "   |          ^          |" << endl;
	cout << "   V          |          V" << endl;
	cout << "********   *******   ********\n";
	cout << "*Flying*   *Chess*   *Mirror*\n";
	cout << "* Keys *-->*Board*   *  Of  *\n";
	cout << "* Room *   * Room*   *Erised*\n";
	cout << "*      *   *     *   * Room *\n";
	cout << "********   *******   ********" << endl;
}

