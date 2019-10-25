/******************************************************************************
 *Program: Final Project - Harry Potter and the Sorcerer's Stone 
 *Author: Alexander Drath
 *Date: 8/11/18
 *Description: Header file for the Menu class is where the game is played at. The 
*	rooms are created initially and linked together by directions. The list is 
*	doubly linked. The player is then created and called to place on the board. 
*	Once the player is placed on the board, instructions are posted on how to
*	play and then the game begins. There are four menu options for the first 5
*	rooms. The first is if they want to search the room to find any food/drinks.
*	There is a random chance that you will find one. If you do, a message will
*	be posted on the screen saying what the item is and then you can either add
*	said item to your inventory if you have the space or you can decide not to.
*	The second option is to use an item that is in the inventory. The third is
*	to move to the next room. If you have not completed the required task in 
*	that room it will not allow you to enter that room. The fourth is an option
*	to quit at any time. There are separate while statements for the potion room
*	and the final battle with voldemort. There is also function that places 
*	Harry Potter on the board within the linked list.
 *****************************************************************************/
#include <string>
#include "HarryPotter.hpp"
#include "Space.hpp"

#ifndef MENU_HPP
#define MENU_HPP
class Menu
{
private:
	int choice = 0;
	int quit = 0;
	std::string intValidation;

public:
	Menu();
	~Menu();
	void startMenu();
	void playGame();
	Space *placeHP(Space *, HarryPotter *);
	Space *moveRooms(Space *, HarryPotter *);
};
#endif
