#include "Cat.hpp"

Cat::Cat() 
    : Animal()
{
    type = "Cat";
    brain = new Brain();
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat(const Cat& other) 
    : Animal(other) 
{
    brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        Brain* newBrain = new Brain(*other.brain);
        delete brain;
        brain = newBrain;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow meow!" << std::endl;
}

void Cat::think() const
{
    std::cout << "Cat is thinking: " << brain->getIdea(0) << std::endl;
}

void Cat::setIdea(int index, const std::string& idea)
{
    brain->setIdea(index, idea);
}
