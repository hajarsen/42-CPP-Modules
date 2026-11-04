#include "Dog.hpp"

Dog::Dog() 
    : AAnimal()
{
    type = "Dog";
    brain = new Brain();
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(const Dog& other) 
    : AAnimal(other)
{
    brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        AAnimal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    return *this;
}

Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const
{
    std::cout << "Woof woof!" << std::endl;
}

void Dog::think() const
{
    std::cout << "Dog is thinking: " << brain->getIdea(0) << std::endl;
}

void Dog::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}
