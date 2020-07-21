/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: This is the header code for the MirrorOfErised class. This is 
*	the final room in the linked list. The class prints a menu for the user 
*	to interact with and decide whether to attack, dodge, eat, or quit the
*	fight with Voldemort.
*****************************************************************************/
#include "Space.hpp"

#ifndef MIRROROFERISEDSPACE_HPP
#define MIRROROFERISEDSPACE_HPP
class MirrorOfErised : public Space
{
private:

public:
	MirrorOfErised();
	~MirrorOfErised();
	virtual int roomMenu();
	virtual int getRoom();
	virtual void printRoomName();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();
};
#endif
