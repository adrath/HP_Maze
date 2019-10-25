/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description:  This is the header file for the Troll class. This is 
*	the fifth room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used. There is no correct
*	item to use for this class.
*****************************************************************************/
#include "Space.hpp"

#ifndef TROLLSPACE_HPP
#define TROLLSPACE_HPP
class Troll : public Space
{
private:

public:
	Troll();
	~Troll();
	virtual int roomMenu();
	virtual int getRoom();
	virtual void printRoomName();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();
};
#endif