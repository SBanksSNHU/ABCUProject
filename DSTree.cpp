#include "DSTREE.hpp"
#include "MENU.hpp"
#include <iostream>

using std::cout;
using std::endl;

// Insert
// Get root
// Search
// Search Recursive
// Print Course
// Print all courses



int Graph::insert(std::unique_ptr<CourseNode> node) {
	if (!node || node->courseID.empty()) {
		return -1; // Invalid node
	}

	const std::string courseId = node->courseID;

	if (nodes.contains(courseId)) {
		return -1; // Already exists
	}

	// Check if all prerequisites exist
	std::vector<std::string> missingPrerequisites;
	for (const auto& prereq : node->coursePrerequisites) {
		if (!search(prereq)) {
			missingPrerequisites.push_back(prereq);
		}
	}

	if (missingPrerequisites.empty()) {
		nodes[courseId] = std::move(node);
		adjacencyList[courseId] = {};
		return 1; // Success
	}
	else {
		tempNotFound.push_back(std::move(node));
		adjacencyList[courseId] = missingPrerequisites;
		return 0; // Prerequisites unresolved
	}
}


CourseNode* Graph::search(const std::string& courseID) {
	if (courseID.empty()) return nullptr;
	auto it = nodes.find(courseID);
	return (it != nodes.end()) ? it->second.get() : nullptr;
}

void Graph::resolveUnresolved() {
	for (auto it = tempNotFound.begin(); it != tempNotFound.end();) {
		auto& node = *it;

		// Skip invalid nodes
		if (!node || node->courseID.empty()) {
			it = tempNotFound.erase(it);
			continue;
		}

		// Check if prerequisites are satisfied
		bool prerequisitesMet = true;
		for (const auto& prereq : node->coursePrerequisites) {
			if (!search(prereq)) {
				prerequisitesMet = false;
				break;
			}
		}

		if (prerequisitesMet) {
			// Move the node into the graph
			std::string courseId = node->courseID;
			nodes[courseId] = std::move(node);
			adjacencyList[courseId] = {};
			it = tempNotFound.erase(it);
		}
		else {
			++it; // Keep in temp list for next attempt
		}
	}
}


void Graph::printAllCourses() {
	for (const auto& [id, node] : nodes) {
		std::cout << "Course: " << node->courseName << " (" << id << ")\n";
		std::cout << "  Prerequisites: ";
		for (const auto& prereq : adjacencyList[id]) {
			if (search(prereq)) { // Only print existing prerequisites
				std::cout << prereq << " ";
			}
		}
		std::cout << "\n";
	}
}

std::vector<CourseNode> Graph::getAllCourses() const {
	std::vector<CourseNode> result;
	for (const auto& [id, node] : nodes) {
		if (node && !node->courseID.empty()) {
			result.push_back(*node); // Safe copy
		}
	}
	return result;
}



