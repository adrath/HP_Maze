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
*	correct bottle then he will have completed the task.
*****************************************************************************/
#include "Space.hpp"

#ifndef POTIONCHALLENGESPACE_HPP
#define POTIONCHALLENGESPACE_HPP
class PotionChallenge : public Space
{
private:
	int select;
public:
	PotionChallenge();
	~PotionChallenge();
	virtual int roomMenu();
	virtual int getRoom();
	virtual void printRoomName();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();
};
#endif
