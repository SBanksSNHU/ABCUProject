#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>




struct CourseNode {
	std::string courseID;
	std::string courseName;
	std::vector<std::string> coursePrerequisites;

	CourseNode(std::string ID, std::string Name, std::vector<std::string> Priors)
		: courseID(std::move(ID)), courseName(std::move(Name)), coursePrerequisites(std::move(Priors)) {
	}
};

class Graph {
private:
    // Centralized node storage (exclusive ownership)
    std::unordered_map<std::string, std::unique_ptr<CourseNode>> nodes;

    // Adjacency list: courseID -> list of prerequisite courseIDs
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

    // Temp storage for unresolved prerequisites
    std::vector<std::unique_ptr<CourseNode>> tempNotFound;

public:
    Graph() = default;
    ~Graph() = default;
    Graph(const Graph&) = delete;              // No copy
    Graph& operator=(const Graph&) = delete;   // No copy assignment
    Graph(Graph&&) = default;                  // Allow move
    Graph& operator=(Graph&&) = default;       // Allow move assignment

    int insert(std::unique_ptr<CourseNode> node);
    CourseNode* search(const std::string& courseID);
    void resolveUnresolved();
    void printAllCourses();
    std::vector<CourseNode> getAllCourses() const;
};