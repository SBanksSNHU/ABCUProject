#include "PARSER.hpp"
#include "MENU.hpp"
#include "DSTREE.hpp"



void readFile(CourseLinkedList &tree) { // This will also load the files into a bst, because why wouldn't you want to do that in an actual program?
	std::ifstream file;
	
	std::filesystem::path currentPath = std::filesystem::current_path();
	std::filesystem::path filePath = currentPath / "courses.csv";

	file.open(filePath);
	std::string line = "";
	
	std::getline(file, line); // Skips first line
	



	while (std::getline(file, line)) {

		std::string courseID;
		std::string courseName;
		std::vector<std::string> coursePrerequisites;
		std::string tempPres; // ??? What does this represent
		

		std::stringstream inputString(line);

		std::getline(inputString, courseID, ',');
		std::getline(inputString, courseName, ',');
		while (std::getline(inputString, tempPres, ',')) {
			coursePrerequisites.push_back(tempPres); // erm, should be to upper but eh...
			if (!inputString) {
				break;
			}
		}

		
		CourseNode* newNode = new CourseNode(courseID, courseName, coursePrerequisites);
		tree.insert(*newNode);
		tree.pushNode(*newNode);
		
		line = "";
	

	}
	tree.notFoundFix();
	// The roots are created, but we need a way to 
	// recursively add things in from tempNotFound and 
	// assign them the proper values
	
	std::cout << "File loaded!" << std::endl;
	file.close();
}

// void appendNode()