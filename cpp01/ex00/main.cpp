#include "Zombie.hpp"

int main() {
    Zombie* heapZombie = newZombie("HeapZom");
    heapZombie->announce();
    delete heapZombie; // must manually destroy heap object

    randomChump("StackZom"); // auto-destroyed at end of function

    return 0;
}