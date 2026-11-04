#include "ClapTrap.hpp"

ClapTrap::ClapTrap() 
    : name("Default")
    , hitPoints(10)
    , energyPoints(10)
    , attackDamage(0)
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) 
    : name(name)
    , hitPoints(10)
    , energyPoints(10)
    , attackDamage(0)
{
    std::cout << "ClapTrap " << this->name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
    *this = other;
    std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot attack!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to attack!" << std::endl;
        return;
    }
    
    energyPoints -= 1;
    std::cout << "ClapTrap " << name << " attacks " << target 
              << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is already dead!" << std::endl;
        return;
    }
    
    if (amount >= hitPoints)
    {
        hitPoints = 0;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " damage and dies!" << std::endl;
    } 
    else 
    {
        hitPoints -= amount;
        std::cout << "ClapTrap " << name << " takes " << amount 
                  << " damage! Remaining HP: " << hitPoints << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0)
    {
        std::cout << "ClapTrap " << name << " is dead and cannot repair!" << std::endl;
        return;
    }
    if (energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " has no energy to repair!" << std::endl;
        return;
    }
    
    energyPoints -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself for " << amount 
              << " HP! New HP: " << hitPoints << std::endl;
}