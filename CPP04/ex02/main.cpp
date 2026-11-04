#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    std::cout << "Test 1: Cannot instantiate AAnimal" << std::endl;
    std::cout << "\nTest 2: Dog and Cat still work" << std::endl;
    
    AAnimal* dog = new Dog();
    AAnimal* cat = new Cat();
    
    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    
    std::cout << cat->getType() << " says: ";
    cat->makeSound();
    
    delete dog;
    delete cat;
    
    std::cout << "\nTest 3: Array of animals" << std::endl;
    AAnimal* animals[4];
    
    for (int i = 0; i < 2; i++)
    {
        animals[i] = new Dog();
    }

    for (int i = 2; i < 4; i++)
    {
        animals[i] = new Cat();
    }

    for (int i = 0; i < 4; i++)
    {
        delete animals[i];
    }

    std::cout << "\nTest 4: Deep copy verification" << std::endl;

    std::cout << "--- Dog Deep Copy ---" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "I'm the original dog!");
    
    Dog dog2(dog1); // Copy constructor
    Dog dog3;
    dog3 = dog1;    // Assignment operator

    std::cout << "Original Dog Idea: "; dog1.think();
    std::cout << "Copy Constructed Dog Idea: "; dog2.think();
    std::cout << "Assigned Dog Idea: "; dog3.think();

    std::cout << "Modifying copies..." << std::endl;
    dog2.setIdea(0, "I'm the copy constructed dog!");
    dog3.setIdea(0, "I'm the assigned dog!");

    std::cout << "Original Dog Idea (Should not change): "; dog1.think();
    std::cout << "Copy Constructed Dog Idea: "; dog2.think();
    std::cout << "Assigned Dog Idea: "; dog3.think();

    std::cout << "\n--- Cat Deep Copy ---" << std::endl;
    Cat cat1;
    cat1.setIdea(0, "I'm the original cat!");
    
    Cat cat2(cat1); // Copy constructor
    Cat cat3;
    cat3 = cat1;    // Assignment operator

    std::cout << "Original Cat Idea: "; cat1.think();
    std::cout << "Copy Constructed Cat Idea: "; cat2.think();
    std::cout << "Assigned Cat Idea: "; cat3.think();

    std::cout << "Modifying copies..." << std::endl;
    cat2.setIdea(0, "I'm the copy constructed cat!");
    cat3.setIdea(0, "I'm the assigned cat!");

    std::cout << "Original Cat Idea (Should not change): "; cat1.think();
    std::cout << "Copy Constructed Cat Idea: "; cat2.think();
    std::cout << "Assigned Cat Idea: "; cat3.think();
    
    return 0;
}