/******************************************************************************
*Program: Final Project - Harry Potter and the Sorcerer's Stone
*Author: Alexander Drath
*Date: 8/11/18
*Description: Source code for the Menu class is where the game is played at. The 
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
#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include <ctime>
#include <cstdlib>
#include "Menu.hpp"
#include "HarryPotter.hpp"
#include "Space.hpp"
#include "FluffySpace.hpp"
#include "DevilSnareSpace.hpp"
#include "FlyingKeysSpace.hpp"
#include "ChessGameSpace.hpp"
#include "TrollSpace.hpp"
#include "PotionChallengeSpace.hpp"
#include "MirrorOfErisedSpace.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::stringstream;
using std::cerr;

/******************************************************************************
 *Description: Default constructor that calls the startMenu() when called.
 *****************************************************************************/
Menu::Menu()
{
	startMenu();
}

/******************************************************************************
*Description: Menu destructor. 
*****************************************************************************/
Menu::~Menu() {}

/******************************************************************************
*Description: This function is the start of game menu which prompts the user 
*	to either play the game or exit the game.
*****************************************************************************/
void Menu::startMenu()
{
	//Randomize the random number generators
	srand(time(NULL));

	//Initialize variables/objects
	string intValidation;

	//Introduction to the game
	cout << endl;
	cout << "Welcome to the 3rd Floor Corridor in Harry Potter and the Sorcerer Stone\n";
	cout << "In this game you will control Harry Potter as he travels through the \n";
	cout << "enchanted rooms set to protect the Sorcerer Stone. You need to hurry if \n";
	cout << "you want to catch up to Professor Snape and stop him from stealing the stone \n";
	cout << "for Voldemort!\n";
	cout << endl;

	//Menu selections
	while (choice != 2)
	{
		cout << "\nPlease choose from the following options:\n";
		cout << "1. Prevent Voldemort from coming back.\n";
		cout << "2. Doom the entire world and walk away.\n";

		//Validate input
		while (true)
		{
			getline(cin, intValidation);
			stringstream ss(intValidation);
			int x;

			if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
			{
				choice = x;
				break;
			}
			cin.clear();
			cerr << "Invalid input. Please enter 1 or 2: \n";
		}
		cout << endl;


		//1. Run game.
		if (choice == 1)
		{
			cout << endl;	
			playGame();
		}

		//2. Exit the game.
		if (choice == 2)
		{
			cout << "Mischief managed.\n";
			cout << endl;
			cout << "Exiting Program... Have a great day!" << endl;
			cout << endl;
		}
	}
}

/******************************************************************************
*Description:  This function is where the game is played at. The 
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
*	and the final battle with voldemort.
*****************************************************************************/
void Menu::playGame()
{
	//Create rooms
	Space *room1 = new Fluffy();
	Space *room2 = new DevilSnare();
	Space *room3 = new FlyingKeys();
	Space *room4 = new ChessGame();
	Space *room5 = new Troll();
	Space *room6 = new PotionChallenge();
	Space *room7 = new MirrorOfErised();

	//Set room locations
	room1->setLocPtr(NULL, room2, NULL, NULL);
	room2->setLocPtr(room1, room3, NULL, NULL);
	room3->setLocPtr(room2, NULL, room4, NULL);
	room4->setLocPtr(room5, NULL, NULL, room3);
	room5->setLocPtr(NULL, room4, room6, NULL);
	room6->setLocPtr(NULL, room7, NULL, room5);
	room7->setLocPtr(room6, NULL, NULL, NULL);

	//Create Harry Potter
	HarryPotter *hp = new HarryPotter();

	//Place Harry Potter in Fluffy's Room
	Space* chamber = placeHP(room1, hp);

	//Instructions for the game
	cout << "Instructions: " << endl;
	cout << "Please use integer values when answering menu prompts. Your character,\n";
	cout << "Harry Potter starts with a health of 100. Every time you perform any \n";
	cout << "actions you will take 1 damage. You must guide yourself and your friends\n";
	cout << "through the chambers to get to Voldemort and prevent him from gaining\n";
	cout << "eternal life.\n";
	cout << endl;
	cout << "Let the game begin!\n";
	cout << endl;
	cout << "GOOD LUCK!! THE ENTIRE WORLD IS COUNTING ON YOU!\n";

	//Pauses the screen after each round so the player can see the results
	cout << "\nPress ENTER to continue...\n";
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	//Room Simulation for the first 5 rooms
	while (hp->getHealth() > 0 && chamber->getRoom() != Space::POTIONS_ROOM)
	{
		//Display the Map/Harry's current location/Harry's Health/Harry's Inventory
		cout << endl;
		cout << "Marauders Map\n";
		cout << "****************\n";
		hp->printMap();
		cout << endl;
		chamber->printRoomName();
		cout << endl;
		cout << "Harry Potter's Health: " << hp->getHealth() << endl;
		cout << endl;
		hp->displayInventory();
		cout << endl;

		//Call to the current room and get the menu prompt selection from user
		int menuPrompt = chamber->roomMenu();

		//Prompt 1: Look Around the Room
		switch (menuPrompt)
		{
			case 1:
			{
				cout << endl;

				//If Harry finds an item in the room
				if (chamber->findItem())
				{
					int maxValue = 11;
					int minValue = 5;
					int randNum = rand() % ((maxValue - minValue) + 1) + minValue;
					if (randNum == HarryPotter::SNAPES_POTION)
					{
						cout << "You pick up one of Snape's Potions off the table\n";
					}
					if (randNum == HarryPotter::BUTTER_BEER)
					{
						cout << "You found a foaming pint of Butter Beer on the table (Heal +15)\n";
					}
					if (randNum == HarryPotter::FIRE_WHISKEY)
					{
						cout << "You found a straight shot of Fire Whiskey on the table (Heal +20)\n";
					}
					if (randNum == HarryPotter::MEAD)
					{
						cout << "You found a pint of Mead in the corner (Heal +10)\n";
					}
					if (randNum == HarryPotter::CHOCOLATE_FROGS)
					{
						cout << "You found a Chocolate Frog on the shelf (Heal +10)\n";
					}
					if (randNum == HarryPotter::BBEFB)
					{
						cout << "You have found a Bertie Bott's Every Flavor Beans on the shelf (Heal unknown)\n";
					}
					if (randNum == HarryPotter::COCKROACH_CLUSTER)
					{
						cout << "You have found some Cockroach Cluster on the floor (Heal +5)\n";
					}
					if (randNum == HarryPotter::CAULDRON_CAKES)
					{
						cout << "You found a Cauldron Cakes on the table (Heal +15)\n";
					}
					cout << endl;

					//Ask player if they want to add item to inventory, if yes, then add to inventory
					cout << "Would You like to place the item into your inventory?\n";
					cout << "You currently have " << (10 - hp->getInventorySize()) << " spaces available.\n";
					cout << "1. Yes\n";
					cout << "2. No\n";
					while (true)
					{
						getline(cin, intValidation);
						stringstream ss(intValidation);
						int x;

						if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
						{
							if (x == 1)
							{
								hp->placeItemInInventory(randNum);
								break;
							}
							else
							{
								break;
							}
						}
						cin.clear();
						cerr << "Invalid input. Please enter 1 or 2: \n";
					}
				}
				else
				{
					cout << "You did not find anything in the room.\n";
				}
				break;
			}

			//Menu Prompt 2: Use item from inventory
			case 2:
			{
				int selection = hp->useItem();
				cout << endl;
				//These items are used for solving the room problems
				if (selection == 1 || selection == 2 || selection == 3 || selection == 4 || selection == 5)
				{
					bool correct = chamber->useCorrectItem(selection - 1);
					if (correct)
					{
						cout << "\nI think we can move to the next room now!\n";
					}
				}
				//These items are food
				else
				{
					hp->healDamage(selection);
				}
				break;
			}

			//Menu Prompt 3: Move to the next room
			case 3:
			{
				//If the task in the room has been completed, move harry to the next room
				if (chamber->taskCompleted())
				{
					Space* temp = placeHP(chamber, hp);
					chamber = temp;
					cout << endl;
					cout << "Harry moves on to the next room.\n";
				}
				//If the task in the room has not been completed, harry takes damage
				else
				{
					cout << endl;
					hp->takeDamage(10);
					cout << "Harry has not solved the puzzle in the room yet.\n";
				}
				break;
			}

			//Menu Prompt 4: Quit the game
			case 4:
			{
				//Double check that they really want to quit the game
				cout << "\nAre you sure you want to quit?\n";
				cout << "1. Yes\n";
				cout << "2. No\n";
				while (true)
				{
					getline(cin, intValidation);
					stringstream ss(intValidation);
					int x;

					if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
					{
						quit = x;
						break;
					}
					cin.clear();
					cerr << "Invalid input. Please enter 1 or 2: \n";
				}
				cout << endl;
				break;
			}
		}
		//If the player say they still want to quit, break the loop and take to main menu
		if (quit == 1)
			break;

		//If Harry is in Devil Snare Room, take damage from the devil snare every round
		if (!chamber->taskCompleted() && chamber->getRoom() == Space::DEVIL_SNARE_ROOM)
		{
			cout << "The devil snare get's tighter every second. Hurry up!\n";
			hp->takeDamage(4);
		}

		//Harry takes damage each round
		cout << endl;
		cout << "End of round! Harry will take 1 damage as Voldemort gets closer to\n";
		cout << "coming back to life.\n";
		hp->takeDamage(1);

		if (hp->getHealth() <= 0)
		{
			cout << "Oh no!! Harry has died!! Voldemort has risen again and there is\n";
			cout << "no one else left to stop him! Way to go buddy...\n";
		}

		//Pauses the screen after each round so the player can see the results
		cout << "\nPress ENTER to continue...\n";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//While loop for when Harry is in the Potions Room.
	while (hp->getHealth() > 0 && chamber->getRoom() == Space::POTIONS_ROOM)
	{
		//Display the Map/Harry's current location/Harry's Health/Harry's Inventory
		cout << endl;
		cout << "Marauders Map\n";
		cout << "****************\n";
		hp->printMap();
		cout << endl;
		chamber->printRoomName();
		cout << endl;
		cout << "Harry Potter's Health: " << hp->getHealth() << endl;
		cout << endl;
		hp->displayInventory();
		cout << endl;

		//Empty one space so that Harry Potter can add Snapes Potion to his inventory
		while (hp->getInventorySize() >= 10)
		{
			cout << "You must use an item as there is no room to add a necessary item needed for\n";
			cout << "this room. Please eat or drink one of your food.\n";
			int choice = hp->useItem();
			cout << endl;
			//These items are used for solving the room problems
			if (choice <= 4)
			{
				cout << "This is not food...\n";
				break;
			}
			//These items are food
			else
			{
				hp->healDamage(choice);
				break;
			}
		}

		//Pauses the screen after each round so the player can see the results
		cout << "\nPress ENTER to continue...\n";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		//Call to the current room and get the menu prompt selection from user
		int selection = chamber->roomMenu();
		cout << endl;

		cout << "You pick up one of Snape's Potions off the table\n";
		hp->placeItemInInventory(HarryPotter::SNAPES_POTION);
		hp->useSnapesPotion(selection);
		cout << endl;

		//Prompts the user to if they would like to eat food or not
		if (hp->getHealth() > 0)
		{
			int eatFood = 1;
			while (eatFood == 1)
			{
				cout << "Would you like to eat some food or have a drink from your inventory?\n";
				cout << "1. Yes\n";
				cout << "2. No\n";
				while (true)
				{
					getline(cin, intValidation);
					stringstream ss(intValidation);
					int x;
					if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
					{
						eatFood = x;
						if (eatFood == 1)
						{
							int choice = hp->useItem();
							cout << endl;
							//These items are used for solving the room problems
							if (choice <= 4)
							{
								cout << "This is not food...\n";
								break;
							}
							//These items are food
							else
							{
								hp->healDamage(selection);
								break;
							}
						}
						else
							break;
					}
					cin.clear();
					cerr << "Invalid input. Please enter 1 or 2: \n";
				}
			}
		}

		//If you correctly guess the right potion, you move on to the next room after taking
		//a shot with Hermionie for good luck.
		if (selection == 3 && hp->getHealth() > 0)
		{
			cout << "You step through the fire to the next room while Hermionie goes back\n";
			cout << "the way she came to take care of Ron. Before Hermionie leaves, she\n";
			cout << "Harry and Hermionie take a shot of Fire Whiskey together.\n";
			hp->healDamage(6);
			Space* temp = placeHP(chamber, hp);
			chamber = temp;
		}

		if (hp->getHealth() <= 0)
		{
			cout << "Oh no!! Harry has died!! Voldemort has risen again and there is\n";
			cout << "no one else left to stop him! Way to go buddy...\n";
			break;
		}

		//Harry takes damage each round
		cout << endl;
		cout << "End of round! Harry will take 1 damage as Voldemort gets closer to\n";
		cout << "coming back to life.\n";
		hp->takeDamage(1);


		//Pauses the screen after each round so the player can see the results
		cout << "\nPress ENTER to continue...\n";
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//While loop for when Harry is in the final room and is battling Voldemort.
	while (hp->getHealth() > 0 && chamber->getRoom() == Space::MIRROR_OF_ERISED_ROOM)
	{
		cout << endl;
		hp->displayInventory();
		cout << endl;
		
		//Call to the current room and get the menu prompt selection from user
		int menuPrompt = chamber->roomMenu();

		int voldemortsAttack = (rand() % 9) + 1;
		int harrysAttack = (rand() % 17) + 3;

		//Prompt 1: Attack
		if (menuPrompt == 1)
		{
			cout << "You attack Voldemort with a simple but effective spell\n";
			hp->attackVoldemort(harrysAttack);
			if (hp->getVoldemortHealth() <= 0)
			{
				cout << "You have defeated Voldemort!!!\n";
				cout << "You have saved the entire world. Dumbledore is so happy he\n";
				cout << "ignores all of your rule breaking and decides to award Griffindor\n";
				cout << "with the House Cup!\n";
				cout << endl;

				//Pauses the screen after each round so the player can see the results
				cout << "\nPress ENTER to continue...\n";
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			}
			else
			{
				cout << "Voldemort strikes back with a curse and hits you\n";
				hp->takeDamage(voldemortsAttack);
			}
		}

		//Menu Prompt 2: Dodge
		if (menuPrompt == 2)
		{
			int chanceToDodge = (rand() % 101) + 1;
			if (chanceToDodge <= 70)
			{
				cout << "You have dodged Voldemorts attack\n";
			}
			else
			{
				cout << "You failed to dodge Voldemort's attack\n";
				hp->takeDamage(voldemortsAttack);
			}
		}

		//Menu Prompt 3: Eat
		if (menuPrompt == 3)
		{
			int eatFood = 1;
			while (eatFood == 1)
			{
				cout << "Would you like to eat some food or have a drink from your inventory?\n";
				cout << "1. Yes\n";
				cout << "2. No\n";
				while (true)
				{
					getline(cin, intValidation);
					stringstream ss(intValidation);
					int x;
					if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
					{
						eatFood = x;
						if (eatFood == 1)
						{
							int choice = hp->useItem();
							cout << endl;
							//These items are used for solving the room problems
							if (choice <= 5)
							{
								cout << "This is not food...\n";
								break;
							}
							//These items are food
							else
							{
								hp->healDamage(choice);
								break;
							}
						}
						else
							break;
					}
					cin.clear();
					cerr << "Invalid input. Please enter 1 or 2: \n";
				}
			}
		}

		//Menu Prompt 4: Quit the game
		if (menuPrompt == 4)
		{
			int quit = 0;
			//Double check that they really want to quit the game
			cout << "\nAre you sure you want to quit?\n";
			cout << "1. Yes\n";
			cout << "2. No\n";
			while (true)
			{
				getline(cin, intValidation);
				stringstream ss(intValidation);
				int x;

				if (ss >> x && !(ss >> intValidation) && (x == 1 || x == 2))
				{
					quit = x;
					break;
				}
				cin.clear();
				cerr << "Invalid input. Please enter 1 or 2: \n";
			}
			//If yes, they still want to quit, break the loop and take to main menu
			if (quit == 1)
				break;
			cout << endl;
		}

		//Harry takes damage each round
		cout << endl;
		cout << "End of round! Harry will take 1 damage as Voldemort gets closer to\n";
		cout << "coming back to life.\n";
		hp->takeDamage(1);

		//Display Harry and Voldemort's Health
		cout << "Harry's Current Health = " << hp->getHealth() << endl;
		cout << "Voldemort's Current Health = " << hp->getVoldemortHealth() << endl;

		//If Harry's health is less than 0, he dies and the game is over.
		if (hp->getHealth() <= 0)
		{
			cout << "Oh no!! Harry has died!! Voldemort has risen again and there is\n";
			cout << "no one else left to stop him! Way to go buddy...\n";
			break;
		}
	}
	

	//Destroy HP and Rooms at the end of the game.
	delete hp;
	delete room1;
	delete room2;
	delete room3;
	delete room4;
	delete room5;
	delete room6;
	delete room7;
}

/******************************************************************************
*Description: This function places Harry Potter on the board within the 
*	linked list.
*****************************************************************************/
Space* Menu::placeHP(Space *place, HarryPotter *harry)
{
	//Place Harry in his current room
	harry->setCurrentLocation(place->getRoom());

	//Move to the next room and return the location
	if (harry->getCurrentLocation() == Space::FLUFFY_ROOM && place->taskCompleted())
	{
		Space *moveRoom = place->getSouth();
		return moveRoom;
	}
	else if (harry->getCurrentLocation() == Space::DEVIL_SNARE_ROOM  && place->taskCompleted())
	{
		Space *moveRoom = place->getSouth();
		return moveRoom;
	}
	else if (harry->getCurrentLocation() == Space::FLYING_KEYS_ROOM  && place->taskCompleted())
	{
		Space *moveRoom = place->getEast();
		return moveRoom;
	}
	else if (harry->getCurrentLocation() == Space::CHESS_GAME_ROOM  && place->taskCompleted())
	{
		Space *moveRoom = place->getNorth();
		return moveRoom;
	}
	else if (harry->getCurrentLocation() == Space::TROLL_ROOM  && place->taskCompleted())
	{
		Space *moveRoom = place->getEast();
		return moveRoom;
	}
	else if (harry->getCurrentLocation() == Space::POTIONS_ROOM  && place->taskCompleted())
	{
		Space *moveRoom = place->getSouth();
		return moveRoom;
	}
	else
	{
		Space *moveRoom = place;
		return moveRoom;
	}
}

