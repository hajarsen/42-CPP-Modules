#include "ClapTrap.hpp"
#include <iostream>

int main() {
    std::cout << "Test 1: Basic functionality" << std::endl;
    ClapTrap robot1("Robo1");
    
    robot1.attack("Target");
    robot1.takeDamage(5);
    robot1.beRepaired(3);
    
    std::cout << "\nTest 2: Energy limits" << std::endl;
    ClapTrap robot2("Robo2");
    
    for (int i = 0; i < 12; i++) {
        robot2.attack("Target");
    }

    std::cout << "\nTest 3: Death" << std::endl;
    ClapTrap robot3("Robo3");
    
    robot3.takeDamage(9);
    robot3.attack("Target");
    robot3.takeDamage(5);
    robot3.beRepaired(10);
    
    return 0;
}