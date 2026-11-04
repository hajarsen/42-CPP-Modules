#include "ScavTrap.hpp"
int main() {
    std::cout << "Test 1: ScavTrap creation" << std::endl;
    ScavTrap scav1("Guardian");
    
    std::cout << "\nTest 2: ScavTrap actions" << std::endl;
    scav1.attack("Intruder");
    scav1.takeDamage(30);
    scav1.beRepaired(15);
    scav1.guardGate();
    
    std::cout << "\nTest 3: Copy and assignment" << std::endl;
    ScavTrap scav2(scav1);
    ScavTrap scav3;
    scav3 = scav2;
    
    std::cout << "\nTest 4: Energy limits" << std::endl;
    ScavTrap scav4("EnergyTest");
    for (int i = 0; i < 55; i++) {
        scav4.attack("Target");
    }
    
    return 0;
}