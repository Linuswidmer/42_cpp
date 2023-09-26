#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        cout << "TEST 1: Construction, Copy Construction and Assignement" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Construction" << endl;
        Animal  *c = new Cat();
        Animal  *d = new Dog();

        // Fill the cat with ideas
        c->newIdea("fish is yummy");
        c->tellIdea();

        cout << endl << "Copy assignement" << endl;
        d = c;
        // Interestingly enough this does not throw a compiler error
        // I thought it would do so as I defined the copy assignement
        // operator for cats and dogs with the brain, but not for animals.
        // interestingly the copy assignment also works for assigning a cat to a dog.
        d->tellIdea();


        cout << endl << "Destruction" << endl;
        
        delete c;
        //delete c2;
    }
}