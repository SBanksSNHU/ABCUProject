#include <iostream>
#include "MENU.hpp"
#include "PARSER.hpp"
#include <thread>
#include <chrono>
#include <Windows.h>
#include "DSTREE.hpp"







 

	void Menus::printMenuOptions() {
		for (int i = 0; i < menuSize; i++) {
			std::cout << i + 1 << ". " << menuOptionsString[i] << std::endl;
		}
	}

	void Menus::getUserInput() {
		std::cin >> userMenuChoice;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(100, '\n');
			(this->*menuOptions_ptr[4])();
		}
		else if (userMenuChoice < 0 || userMenuChoice > menuSize) {
			std::cout << "Invalid input! Please input a valid menu choice." << std::endl;
			
			getUserInput();
		}
		else {
			setMenuChoice(userMenuChoice);
			if (userMenuChoice) {

			}
			(this->*menuOptions_ptr[userMenuChoice - 1])(); // https://stackoverflow.com/questions/6586205/what-are-the-pointer-to-member-operators-and-in-c

		}
	}


	void Menus::optionOne() { // Loading files
		setMenuChoice(1);
		if (menuDepth > 0) {
			std::cout << "Anything Else?" << std::endl;
		}
		menuDepth++;
	}
	void Menus::optionTwo() {
		setMenuChoice(2);

		std::vector<CourseNode> nodes = currentTree.getAllCourses();
		if (menuDepth > 0) {
			std::cout << "Anything Else?" << std::endl;
		}
		std::cout << "Upcoming schedule" << std::endl;
		for (int i = 0; i < nodes.size(); i++) {
			std::cout << nodes[i].courseID << std::endl;
		}
		
		menuDepth++;
	}
	void Menus::optionThree() { // Print course and requirements
		setMenuChoice(3);
		currentTree.printCourse();

		if (menuDepth > 0) {
			std::cout << "Anything Else?" << std::endl;
		}
		currentTree.printAllCourses();
		menuDepth++;
	}

	void Menus::optionFour() {
		setMenuChoice(4);
		std::cout << "Goodbye!" << std::endl;
		setRunFlag(false);
		std::this_thread::sleep_for(std::chrono::milliseconds(2000));

		exit(0);
	}

	void Menus::optionNA() { // The case in which a non int was input
		HANDLE  hConsole;
		int k;

		std::this_thread::sleep_for(std::chrono::milliseconds(400)); // 400
		std::cout << "\nerm..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(800)); // 800
		std::cout << "I see you've chosen to input alpha characters." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1400)); // 800
		std::cout << "Time to install my virus!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		std::cout << "." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(700));
		std::cout << "." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(600));
		std::cout << "." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "!" << std::endl;


		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		for (k = 1; k < 255; k++)
		{
			// pick the colorattribute k you want
			SetConsoleTextAttribute(hConsole, k);
			std::cout << "!" << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(6));
		}
		SetConsoleTextAttribute(hConsole, 1);

		std::cout << "10/10 would joke again :)\n PS, My mother's birthday is on Halloween! Very spooky." << std::endl;
		exit(0);


	}

	// Set 
	void Menus::setMenuChoice(int x) {
		userMenuChoice = x;
	}
	void Menus::setRunFlag(bool x) {
		runFlag = x;
	}

	// Get 
	int Menus::getMenuChoice() {
		return userMenuChoice;
	}
	bool Menus::getRunFlag() {
		return runFlag;
	}









