#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    // test assigning a Cat to an animal object

    Animal  *a = new Animal();
    Animal  *c = new Cat();
    //Cat     *c_copy = new Cat(*c);
    Animal  *d = new Dog();

    // base tests correct implementation
    std::cout << std::endl << "Correct implementation:" << std::endl;
    std::cout << a->getType() << std::endl;
    std::cout << c->getType() << std::endl;
    std::cout << d->getType() << std::endl;
    a->makeSound();
    c->makeSound();
    d->makeSound();

    // copy constructor
    //cout << c_copy->getType() << endl;
    //c_copy->makeSound();
    delete a;
    delete c;
    delete d;

    std::cout << std::endl << "Incorrect implementation:" << std::endl;
    WrongAnimal *w_a = new WrongAnimal();
    WrongAnimal *w_c = new WrongCat();

    std::cout << w_a->getType() << std::endl;
    std::cout << w_c->getType() << std::endl;
    w_a->makeSound();
    w_c->makeSound();

    delete w_a;
    delete w_c;
}