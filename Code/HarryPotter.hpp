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
#include <deque>

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

class HarryPotter
{
public:
	HarryPotter();
	~HarryPotter();

	enum Items
	{
		FLUTE,
		WAND,
		BROOMSTICK,
		CHESS_PIECE,
		SNAPES_POTION,
		BUTTER_BEER,
		FIRE_WHISKEY,
		MEAD,
		CHOCOLATE_FROGS,
		BBEFB,
		COCKROACH_CLUSTER,
		CAULDRON_CAKES
	};

	//Inventory Functions
	void displayInventory();
	void placeItemInInventory(int);
	void useSnapesPotion(int);
	int useItem();

	//Harry and Voldemort's Health Functions
	void takeDamage(int);
	void healDamage(int);
	void attackVoldemort(int);
	int getHealth();
	int getVoldemortHealth();

	//Map and Location Functions
	void setCurrentLocation(int);
	void printMap();
	int getCurrentLocation();
	int getInventorySize();

private:
	std::deque<Items> inventory;	//Harry's inventory
	int voldemort = 100;			//Voldemort's health
	int health;						//Harry's Health
	int damage;						//Damage
	int currentLocation;			//Current location of Harry
};
#endif
