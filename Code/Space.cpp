/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the abstract class for the rooms that form the linked list.
*	This class sets the directions that each room is located in relation to
*	the other rooms. This is also where the direction in which to move can be
*	returned from. This is used in the Menu class to move Harry from one room
*	to the next. Finally, the chance of finding an object is generated in this 
*	class.
*****************************************************************************/
#include <iostream>
#include <cstdlib>
#include "Space.hpp"
using std::cout;

/******************************************************************************
*Description: This class is the abstract base class for all of the rooms in 
*	the game. The Space class contains the enum Locations for game to 
*	recognize each of the rooms. It is also where the linking of the rooms 
*	is done at. There are 4 different directions that the rooms can be 
*	situated (north, south, east, west).
*****************************************************************************/
Space::Space(Location room)
{
	task = false;
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
	this->room = room;
}

/******************************************************************************
*Description: Sets up the rooms by linking the room pointers together for what 
*	is north, south, east and west of each other. If you cannot go next north, 
*	south, east or west, then they will equal NULL so as not to allow the user 
*	to go that direction.
*****************************************************************************/
void Space::setLocPtr(Space *north, Space *south, Space *east, Space *west)
{
	this->north = north;
	this->south = south;
	this->east = east;
	this->west = west;
}

/******************************************************************************
*Description: returns the room enum name.
*****************************************************************************/
int Space::getRoom()
{
	return currentLocation;
}

/******************************************************************************
*Description: prints a display of the the room name for the user to see
*****************************************************************************/
void Space::printRoomName()
{
	cout << "Harry's Current Location: Nowhere\n";
}

/******************************************************************************
*Description: returns the north pointer.
*****************************************************************************/
Space *Space::getNorth()
{
	return north;
}

/******************************************************************************
*Description: returns the south pointer.
*****************************************************************************/
Space *Space::getSouth()
{
	return south;
}

/******************************************************************************
*Description: returns the east pointer.
*****************************************************************************/
Space *Space::getEast()
{
	return east;
}

/******************************************************************************
*Description: returns the west pointer.
*****************************************************************************/
Space *Space::getWest()
{
	return west;
}

/******************************************************************************
* Description: returns 100 in Space class. Virtual function.
*****************************************************************************/
int Space::roomMenu()
{
	return 100;
}

/******************************************************************************
*Description: Search the room for any items that may be around. There is a 
*	random chance (70%) that the user will find an item such as food or drink 
*	that they can either add to their inventory or not. If an item is “found” 
*	then true is returned, otherwise false is returned.
*****************************************************************************/
bool Space::findItem()
{
	int findSomething = (rand() % 10) + 1;
	if (findSomething <= 7)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************************
*Description: This says that the user selected the correct item necessary to 
*	complete the task needed to move on. If the user selects the correct item, 
*	then true is returned, otherwise, false is returned.
*****************************************************************************/
bool Space::useCorrectItem(int itemSelection)
{
	if (itemSelection == 4)
	{
		task = true;
		return true;
	}
	else
	{
		return false;
	}
}

/******************************************************************************
*Description: This function tells whether the required task to move to the next 
*	room is completed or not. If it is, true is returned, if not, false.
*****************************************************************************/
bool Space::taskCompleted()
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

/******************************************************************************
*Description: Pure virtual destructor for the class
*****************************************************************************/
Space::~Space() {}
