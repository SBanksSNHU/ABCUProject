#include <fstream>
#include <sstream>
#include <filesystem>
#include <memory>
#include <stdexcept>

#include "PARSER.hpp"
#include "MENU.hpp"
#include "DSTREE.hpp"


void readFile(Graph& graph) {

    std::ifstream file;
    std::filesystem::path filePath = std::filesystem::current_path() / "courses.csv";

    file.open(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Failed to open courses.csv");
    }

    std::string line;
    std::getline(file, line); // Skip header

    std::vector<std::unique_ptr<CourseNode>> tempNodes; // For RAII safety

    while (std::getline(file, line)) {
        std::string courseID, courseName;
        std::vector<std::string> coursePrerequisites;

        std::stringstream inputString(line);

        // Read course ID
        if (!std::getline(inputString, courseID, ',')) continue;

        // Read course name
        if (!std::getline(inputString, courseName, ',')) continue;

        if (courseID.empty() || courseName.empty()) {
            std::cerr << "Skipping invalid line: " << line << "\n";
            continue;
        }

        // Read prerequisites
        std::string tempPres;
        while (std::getline(inputString, tempPres, ',')) {
            if (!tempPres.empty()) {  // Skip empty fields
                coursePrerequisites.push_back(tempPres);
            }
        }

        // Create node with unique_ptr for automatic cleanup
        auto newNode = std::make_unique<CourseNode>(
            std::move(courseID),
            std::move(courseName),
            std::move(coursePrerequisites)
        );

        // Store temporarily for RAII safety
        tempNodes.push_back(std::move(newNode));
    }

    file.close();

    // Insert all nodes into the graph
    for (auto& node : tempNodes) {
        graph.insert(std::move(node));  // Transfer ownership to graph
    }

    // Resolve unresolved prerequisites
    graph.resolveUnresolved();

    std::cout << "File loaded!" << std::endl;
}
