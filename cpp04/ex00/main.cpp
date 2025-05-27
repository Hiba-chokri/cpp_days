#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
// #include "WrongAnimal.hpp"
// #include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
// std::cout << j->getType() << " " << std::endl;
// std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();
meta->makeSound();
// ******** WrongAnimal class
// const WrongAnimal* meta = new WrongAnimal();
// WrongCat b;
// const WrongAnimal i = b;
// // std::cout << j->getType() << " " << std::endl;
// // std::cout << i->getType() << " " << std::endl;
// i.makeSound(); //will output the cat sound!
// meta->makeSound();
/// ***** even if we used virtual and we didnt use a pointer of type base class
// const Animal* meta = new Animal();
// const Animal j = Dog();
// const Animal i = Cat();
// // std::cout << j->getType() << " " << std::endl;
// // std::cout << i->getType() << " " << std::endl;
// i.makeSound(); //will output the cat sound!
// j.makeSound();
// meta->makeSound();
return 0;
}