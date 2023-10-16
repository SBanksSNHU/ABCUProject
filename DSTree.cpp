#include "DSTREE.hpp"
#include "MENU.hpp"
#include <iostream>

using std::cout;
using std::endl;

int  CourseLinkedList::insert(CourseNode node) {
	if (node.coursePrerequisites.empty()) {
		root.push_back(node);
	}
	else {// if it does have prerequisites

		for (int i = 0; i < node.coursePrerequisites.size(); i++) {
			int existsCount = 0;
			bool prerequisiteFound = false;

			// Search for the prerequisite node
			CourseNode* prerequisiteNode = search(node.coursePrerequisites[i]);
			if (prerequisiteNode) {
				existsCount++;
				prerequisiteFound = true;
				// Append the node as a child to the prerequisite node
				prerequisiteNode->children.push_back(node);
			}

			// Handle the case where the prerequisite was not found
			if (!prerequisiteFound) {
				tempNotFound.push_back(node);
			}
			if (existsCount == node.coursePrerequisites.size()) { // all prerequisites exist
				for (int i = 0; i < node.coursePrerequisites.size(); i++) {
					CourseNode* prerequisiteNode = search(node.coursePrerequisites[i]);
					if (prerequisiteNode) {
						// Add the current node as a child to the prerequisite node
						prerequisiteNode->children.push_back(node);
						return 1;
					}
					else { // atleast 1 prerequisite doesn't exist
						tempNotFound.push_back(node);
						
						return 0;
					}
				}
			}
			
			// check prerequisites if courses found in tree
			// if found make them child,
			// if not found


			// Search for every node in 	
			// // If prerequisites = Null, Root
		// Search for every prerequisite and store a pointer of it in
		}

	}
	
}


CourseNode* CourseLinkedList::getRoot() {
	return &root[0];
}


//Ok look, this function creates a tree, but a forest is needed


CourseNode* CourseLinkedList::search(std::string name) {
	// Will need to search every root to find value
	for (int i = 0; i < root.size(); i++) {
		CourseNode* foundNode = searchRe(&root[i], name);
		if (foundNode) {
			return foundNode;  // If found in any root, return it
		}
	}

	return nullptr;  // Not found in any root
}

CourseNode* CourseLinkedList::searchRe(CourseNode* startNode, std::string name) {
	if (startNode->courseID == name) {
		return startNode;
	}

	for (int j = 0; j < startNode->children.size(); j++) {
		CourseNode* foundNode = searchRe(&startNode->children[j], name);
		if (foundNode) {
			return foundNode;  // If found in child, return it
		}
	}

	return nullptr;  // Not found in this subtree
}



void CourseLinkedList::printCourse() {
	// Search for the node first, assign to value
	CourseNode* node;
	std::string userCourse;
	cout << "What course are you looking for?[ABC-123]" << endl;
	std::cin >> userCourse;
	node = search(userCourse);
	if (node) {
		cout << "ID: " << node->courseID << "\nName: " << node->courseName <<
			"\nPrerequisites: ";
		for (int i = 0; i < node->coursePrerequisites.size(); i++) {
			cout << node->coursePrerequisites[i] << ", \n";
		}

	}
	else {
		cout << "Node " << userCourse << " does not exist.\n";
	}

	//CourseNode* node = search(name);


}


void CourseLinkedList::notFoundFix() {
	int pick = 0;

	while (!tempNotFound.empty()) {
		CourseNode node = tempNotFound.at(pick);
		tempNotFound.erase(tempNotFound.begin() + pick);
		insert(node);
		
		
		// remove element call, function again
	}
}

std::vector<CourseNode> CourseLinkedList::getNotFound() {
	return tempNotFound;
}
void CourseLinkedList::printAllCourses() {
	cout << "Upcoming courses:\n";
}


	void CourseLinkedList::pushNode(CourseNode node) {
		allCourses.push_back(node);
	}
	std::vector<CourseNode> CourseLinkedList::getAllCourses() {
		return allCourses;
	}
