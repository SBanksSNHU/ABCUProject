#include <iostream>
#include "MENU.hpp"
#include "DSTREE.hpp"
#include "PARSER.hpp"

int main()
{
    Graph graph;
    Menus mainMenu(graph);
    
    
    std::cout << "Hello, what would you like to do?" << std::endl;
    do {
        mainMenu.resetTextColor();
        mainMenu.printMenuOptions();
        mainMenu.getUserInput();
        
    } while (mainMenu.getRunFlag());

    return 0;
}
