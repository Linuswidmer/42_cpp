#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    // test assigning a Cat to an animal object

    Animal  *a = new Animal();
    Animal  *c = new Cat();
    //Cat     *c_copy = new Cat(*c);
    Animal  *d = new Dog();

    // base tests correct implementation
    cout << endl << "Correct implementation:" << endl;
    cout << a->getType() << endl;
    cout << c->getType() << endl;
    cout << d->getType() << endl;
    a->makeSound();
    c->makeSound();
    d->makeSound();

    // copy constructor
    //cout << c_copy->getType() << endl;
    //c_copy->makeSound();
    delete a;
    delete c;
    delete d;
}