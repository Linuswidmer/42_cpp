#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        cout << "TEST 1: Construction, Copy Construction and Assignement" << endl;
        cout << "-------------------------------------------------------" << endl;
        cout << "Construction" << endl;
        try
        {
            Animal  *c = new Cat();
            Animal  *d = new Dog();

            // Fill the cat with ideas
            c->newIdea("fish is yummy");
            c->tellIdea();

             cout << endl << "Copy assignment" << endl;
            *d = *c;

            // the dog thinks it is a cat now and also gets the same ideas
            // the sound it makes does not change however
            d->tellIdea();
            d->makeSound();
            cout << d->getType() << endl;

            cout << endl << "Copy Constructor: " << endl;
            Animal c_copy = new Cat(*c);

            cout << endl << "Destruction" << endl;
            delete c;
            delete d;
        } 
        catch (const std::bad_alloc& e) 
        {
            cerr << "Allocation failed: " << e.what() << endl;
        }
        cout << endl << "TEST 2: Subject tests" << endl;
        cout << "-------------------------------------------------------" << endl;
        {
            try
            {
                Animal *animal_arr[10];

                for(int i = 0; i < 10; i++)
                {
                    if (i % 2 == 0)
                        animal_arr[i] = new Cat();
                    else
                        animal_arr[i] = new Dog();
                }
                for (int i = 0; i < 10; i++)
                {
                    delete animal_arr[i];
                }
            }
            catch(const bad_alloc& e)
            {
                std::cerr << "Allocation failed: " << e.what() << '\n';
            }
            
        }
    }
}