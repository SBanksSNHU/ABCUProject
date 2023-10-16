#pragma once
#include <string>
#include <vector>



struct CourseNode { // Nodes objects
private:
	std::vector<std::string> allCourses;
public:

	
	std::string courseID;
	std::string courseName;
	std::vector<std::string> coursePrerequisites;
	std::vector<CourseNode> children; 

	CourseNode(std::string ID, std::string Name, std::vector<std::string> Priors):
		courseID(ID), courseName(Name), coursePrerequisites(Priors)
	{	
		allCourses.push_back(Name);
	}

};
		
class CourseLinkedList{

	std::vector<CourseNode> root;
	std::vector<CourseNode> tempNotFound;
	std::vector<CourseNode> allCourses;


public:
	CourseNode* getRoot();
	std::vector<CourseNode> getNotFound();
	int insert(CourseNode node);			// Insertion based on priors					
	CourseNode* search(std::string name);	// Searches for a node
	CourseNode* searchRe(CourseNode* startNode, std::string name);
	void printCourse();		// Print
	void notFoundFix();		// This should fix the tempNotFound
	void printAllCourses();
	void pushNode(CourseNode node);
	std::vector<CourseNode> getAllCourses();
	//when a new object is created, we need to check and fix tempNotFound

};
