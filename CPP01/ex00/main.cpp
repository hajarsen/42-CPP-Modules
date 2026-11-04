#include "Zombie.hpp"

int main() {

    Zombie* heapZombie = newZombie("HeapZombie");
    heapZombie->announce();
    delete heapZombie;
    randomChump("StackZombie");
    Zombie* anotherHeapZombie = newZombie("Bob");
    anotherHeapZombie->announce();
    delete anotherHeapZombie;

    return 0;
}