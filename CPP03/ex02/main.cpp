#include "FragTrap.hpp"

int main() {
    std::cout << "Test 1: FragTrap creation" << std::endl;
    FragTrap frag1("Bomber");
    
    std::cout << "\nTest 2: FragTrap actions" << std::endl;
    frag1.attack("Enemy");
    frag1.takeDamage(50);
    frag1.beRepaired(25);
    frag1.highFivesGuys();
    
    std::cout << "\nTest 3: Copy and assignment" << std::endl;
    FragTrap frag2(frag1);
    FragTrap frag3;
    frag3 = frag2;
    
    std::cout << "\nTest 4: Death test" << std::endl;
    FragTrap frag4("Test");
    frag4.takeDamage(150);
    frag4.attack("Target");
    frag4.highFivesGuys();
    
    return 0;
}