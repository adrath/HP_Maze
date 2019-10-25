/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description:  This is the header file for the DevilSnare class. This is 
*	the second room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether they want to look for items in the room,
*	use an item in the inventory, try and move on to the next room, or quit the 
*	game. The correct item need to move to the next room is kept in the class 
*	and the task is accomplished if the correct item is used.
*****************************************************************************/
#include "Space.hpp"

#ifndef DEVILSNARESPACE_HPP
#define DEVILSNARESPACE_HPP
class DevilSnare : public Space
{
private:

public:
	DevilSnare();
	~DevilSnare();
	virtual int roomMenu();
	virtual int getRoom();
	virtual void printRoomName();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();
};
#endif