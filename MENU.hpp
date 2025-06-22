#pragma once
#include <vector>
#include <functional>
#include <string>
#include "DSTREE.hpp"
#include "PARSER.hpp"

enum ConsoleColor {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	YELLOW = 6,
	WHITE = 7,
	BRIGHT = 8
};


class Menus {
	const std::vector<std::string> menuOptionsString		// Displays options to user
	{
		"Load Data Structure",
		"Print Course List",
		"Print Course",
		"Exit"
	};
	bool runFlag;
	int menuDepth;				// How deep you are into menus
	int menuSize;				// Amount of options in the menu
	int userMenuChoice;			// The user's menu choice
	Graph& currentGraph;

	// Option three


public:

	// Option 9 is VERY SPECIAL because of the gap, so I'll just change it to 4 :)



	void optionOne();			// Load data structure
	void optionTwo();			// Printing course list
	void optionThree();			// Print specified course
	void optionFour();			// Close the program,
	void optionNA();			// Called when choice isn't valid

	// Set 
	void setMenuChoice(int x);
	void setRunFlag(bool x);

	// Get 
	int getMenuChoice();
	bool getRunFlag();

	void clearScreen();

	void changeTextColor(ConsoleColor color);

	void resetTextColor();

	void printMenuOptions();	// Iterate over vector


	const std::vector<void (Menus::*)()> menuOptions_ptr //std::vector<std::function<void(Menus*)>>menuOptions_ptr // Function pointers
	{
		&Menus::optionOne,
		&Menus::optionTwo,
		&Menus::optionThree,
		&Menus::optionFour,
		&Menus::optionNA
	};

	void getUserInput();


	Menus(Graph& graph)
		: runFlag(true),
		menuDepth(0),
		menuSize(menuOptionsString.size()),
		userMenuChoice(0),
		currentGraph(graph)
	{
		readFile(currentGraph);
	}

};
