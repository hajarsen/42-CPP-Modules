#include "FragTrap.hpp"

FragTrap::FragTrap() {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap Default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
  hitPoints = 100;
  energyPoints = 100;
  attackDamage = 30;
  std::cout << "FragTrap " << this->name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other) {
  *this = other;
  std::cout << "FragTrap Copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
  if (this != &other)
    ClapTrap::operator=(other);
  std::cout << "FragTrap Copy assignment operator called" << std::endl;
  return *this;
}

FragTrap::~FragTrap() {
  std::cout << "FragTrap " << name << " destructor called" << std::endl;
}

void FragTrap::attack(const std::string &target) {
  if (hitPoints == 0) {
    std::cout << "FragTrap " << name << " is dead and cannot attack!"
              << std::endl;
    return;
  }
  if (energyPoints == 0) {
    std::cout << "FragTrap " << name << " has no energy to attack!"
              << std::endl;
    return;
  }

  energyPoints -= 1;
  std::cout << "FragTrap " << name << " attacks " << target << ", causing "
            << attackDamage << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys(void) {
  std::cout << "FragTrap " << name << " requests a positive high five!"
            << std::endl;
}