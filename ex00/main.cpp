#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    std::cout << "Test 1 : Correct polymorphism" << std::endl;
    const Animal* meta = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << dog->getType() << " says: ";
    dog->makeSound();
    std::cout << cat->getType() << " says: ";
    cat->makeSound();
    std::cout << meta->getType() << " says: ";
    meta->makeSound();

    delete meta;
    delete dog;
    delete cat;

    std::cout << "\nTest 2 : Wrong (no virtual)" << std::endl;
    const WrongAnimal* wrong = new WrongAnimal();
    const WrongCat* wrongCat = new WrongCat();
    const WrongAnimal* wrongCatAsAnimal = wrongCat;

    std::cout << wrong->getType() << " says: ";
    wrong->makeSound();
    std::cout << wrongCatAsAnimal->getType() << " says: ";
    wrongCatAsAnimal->makeSound();

    delete wrong;
    delete wrongCat;

    std::cout << "\nExtra tests" << std::endl;
    std::cout << "--- Copy Constructor Test ---" << std::endl;
    Dog dog1;
    Dog dog2(dog1); // Copy constructor
    
    Cat cat1;
    Cat cat2(cat1); // Copy constructor

    std::cout << "--- Copy Assignment Operator Test ---" << std::endl;
    Dog dog3;
    dog3 = dog1;    // Copy assignment
    
    Cat cat3;
    cat3 = cat1;    // Copy assignment

    std::cout << "--- Sound Check ---" << std::endl;
    dog1.makeSound();
    dog2.makeSound();
    dog3.makeSound();
    
    cat1.makeSound();
    cat2.makeSound();
    cat3.makeSound();

    return 0;
}
