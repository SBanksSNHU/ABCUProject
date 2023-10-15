#pragma once
#include <string>
#include <vector>



struct CourseNode { // Nodes objects


	
	std::string courseID;
	std::string courseName;
	std::vector<std::string> coursePrerequisites;
	std::vector<CourseNode> children; 

	CourseNode(std::string ID, std::string Name, std::vector<std::string> Priors):
		courseID(ID), courseName(Name), coursePrerequisites(Priors)
	{	}

};
		
class CourseLinkedList{

	std::vector<CourseNode> root;
	std::vector<CourseNode> tempNotFound;


public:
	CourseNode* getRoot();
	void insert(CourseNode node);			// Insertion based on priors					
	CourseNode* search(std::string name);	// Searches for a node
	CourseNode* searchRe(CourseNode* startNode, std::string name);
	void printCourse(std::string name);		//Print
	
	// when a new object is created, we need to check and fix tempNotFound

};
