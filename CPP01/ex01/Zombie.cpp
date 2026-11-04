#include "Zombie.hpp"

Zombie::Zombie() : name("Unnamed")
{
    
}

Zombie::~Zombie()
{
    std::cout << name << " destroyed" << std::endl;
}

void Zombie::setName(std::string zombieName)
{
    name = zombieName;
}

void Zombie::announce() const
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}