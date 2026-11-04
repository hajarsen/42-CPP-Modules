#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "Test 1: Basic allocation/deallocation" << std::endl;
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    delete j;
    delete i;
    
    std::cout << "\nTest 2: Array of animals" << std::endl;
    Animal* animals[4];
    
    for (int idx = 0; idx < 2; idx++) {
        animals[idx] = new Dog();
    }
    for (int idx = 2; idx < 4; idx++) {
        animals[idx] = new Cat();
    }
    for (int idx = 0; idx < 4; idx++) {
        delete animals[idx];
    }

    std::cout << "\nTest 3: Deep copy" << std::endl;
    Dog originalDog;
    originalDog.setIdea(0, "I want a bone");
    
    Dog copiedDog = originalDog;
    copiedDog.setIdea(0, "I want a ball");
    
    std::cout << "Original dog idea: ";
    originalDog.think();
    std::cout << "Copied dog idea: ";
    copiedDog.think();
    
    std::cout << "\nTest 4: Assignment operator deep copy" << std::endl;
    Dog dog1;
    dog1.setIdea(0, "Original idea");
    
    Dog dog2;
    dog2 = dog1;
    dog2.setIdea(0, "Changed idea");
    
    std::cout << "Dog1 idea: ";
    dog1.think();
    std::cout << "Dog2 idea: ";
    dog2.think();
    
    std::cout << "\nTest 5: Same for cats" << std::endl;
    Cat cat1;
    cat1.setIdea(0, "Chase mice");
    
    Cat cat2(cat1);
    cat2.setIdea(0, "Sleep on sofa");
    
    std::cout << "Cat1 idea: ";
    cat1.think();
    std::cout << "Cat2 idea: ";
    cat2.think();

    std::cout << "\nTest 6: Cat assignment deep copy" << std::endl;
    Cat cat3;
    cat3 = cat1;
    cat3.setIdea(0, "Climb curtains");

    std::cout << "Cat1 idea: ";
    cat1.think();
    std::cout << "Cat3 idea: ";
    cat3.think();
    
    return 0;
}
