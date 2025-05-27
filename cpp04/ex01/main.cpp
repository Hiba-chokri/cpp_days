#include "Brain.hpp"
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

    // const Animal* f;
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();

    // // const Animal *A(f);
    // // (void)A;
    // j->makeSound();
    // f->makeSound();
    // i->makeSound();
    // f = i;
    // f->makeSound();
    // delete j;//should ./    not create a leak
    // delete i;
    // return (0);

int main() {
    const int size = 4;
    Animal* animals[size];

    // Fill the first half with Dogs and the second half with Cats
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\nTesting Deep Copy:\n";

    Dog originalDog;
    originalDog.setIdea(0, "Chase the ball");
    Dog copiedDog = originalDog; // Should call the copy constructor

    originalDog.setIdea(0, "Eat food"); // Changing original shouldn't affect copy

    std::cout << "Original Dog idea[0]: " << originalDog.getIdea(0) << std::endl;
    std::cout << "Copied Dog idea[0]: " << copiedDog.getIdea(0) << std::endl;

    std::cout << "\nDeleting Animals:\n";

    // Properly delete all animals
    for (int i = 0; i < size; ++i) {
        delete animals[i]; // Should call correct destructors
    }
    return 0;
}