/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the header file for the Fluffy class. This class 
*	represents the first room of the linked list of rooms. Fluffy, Hagrid's
*	3-headed dog, lives in the room and Harry has to get past him to move to
*	the next room. The class prints a menu for the user to interact with and
*	decide whether they want to look for items in the room, use an item in 
*	the inventory, try and move on to the next room, or quit the game. The 
*	correct item need to move to the next room is kept in the class and the
*	task is accomplished if the correct item is used.
*****************************************************************************/
#include "Space.hpp"

#ifndef FLUFFYSPACE_HPP
#define FLUFFYSPACE_HPP
class Fluffy : public Space
{
private:

public:
	Fluffy();
	~Fluffy();
	virtual int roomMenu();
	virtual int getRoom();
	virtual void printRoomName();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();
};
#endif