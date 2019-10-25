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
#ifndef SPACE_HPP
#define SPACE_HPP

//Forward Declaration
class HarryPotter;

class Space
{
public:
	enum Location
	{
		FLUFFY_ROOM,
		DEVIL_SNARE_ROOM,
		FLYING_KEYS_ROOM,
		CHESS_GAME_ROOM,
		TROLL_ROOM,
		POTIONS_ROOM,
		MIRROR_OF_ERISED_ROOM
	};

	Space(Location room);
	virtual ~Space() = 0;
	void setLocPtr(Space*, Space*, Space*, Space*);
	Space *getNorth();
	Space *getSouth();
	Space *getEast();
	Space *getWest();
	virtual int getRoom();
	virtual void printRoomName();
	virtual int roomMenu();
	bool findItem();
	virtual bool useCorrectItem(int);
	virtual bool taskCompleted();

protected:
	
	int actionSelection;
	int val;
	bool task;

	int currentLocation;

	Location room;

	//Directions
	Space *north;
	Space *south;
	Space *east;
	Space *west;
};
#endif