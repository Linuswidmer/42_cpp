#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
    {
        Animal  *a = new Animal();
        Animal  *c = new Cat();
        Animal  *d = new Dog();

        std::cout << std::endl << "------- BASE TESTS CORRECT ---------" << std::endl;
        std::cout << a->getType() << std::endl;
        std::cout << c->getType() << std::endl;
        std::cout << d->getType() << std::endl;
        a->makeSound();
        c->makeSound();
        d->makeSound();

        std::cout << std::endl << "------- COPY CONSTRUCTOR / ASSIGNEMENT ---------" << std::endl;
        Cat *c_copy = new Cat(* dynamic_cast<Cat*>(c));
        Cat *c_new = new Cat();
        std::cout << c_copy->getType() << std::endl;
        c_copy->makeSound();
        * dynamic_cast<Cat*>(c_new) = * dynamic_cast<Cat*>(c);

        std::cout << std::endl << "------- DESTRUCTION ---------" << std::endl;
        delete a;
        delete c;
        delete c_copy;
        delete c_new;
        delete d;
    }

    {
        std::cout << std::endl << "------- BASE TESTS INCORRECT ---------" << std::endl;

        WrongAnimal *w_a = new WrongAnimal();
        WrongAnimal *w_c = new WrongCat();

        std::cout << w_a->getType() << std::endl;
        std::cout << w_c->getType() << std::endl;
        w_a->makeSound();
        w_c->makeSound();

        std::cout << std::endl << "------- DESTRUCTION ---------" << std::endl;
        delete w_a;
        delete w_c;
    }
}