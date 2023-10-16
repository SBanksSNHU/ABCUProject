#include <iostream>
#include "MENU.hpp"
#include "DSTREE.hpp"
#include "PARSER.hpp"
int main()
{
    CourseLinkedList tree;
    readFile(tree);
    
    Menus main(tree);
    std::cout << "Hello, what would you like to do?" << std::endl;
    do {
        
        main.printMenuOptions();
        main.getUserInput();
        
    } while (main.getRunFlag());

    
  

    return 0;
}
