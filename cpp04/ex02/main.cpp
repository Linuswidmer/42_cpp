#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
    {
        std::cout << "TEST 1: Construction, Copy Construction and Assignement" << std::endl;
        std::cout << "-------------------------------------------------------" << std::endl;
        std::cout << "Construction" << std::endl;
        try
        {
            // this is now not allowed
            // Animal a = new Animal();

            std::cout << "CONSTRUCTION" << std::endl;
            Animal  *c = new Cat();
            Animal  *c2 = new Cat();

            // Fill the cat with ideas
            dynamic_cast<Cat*>(c)->newIdea("fish is yummy");
            dynamic_cast<Cat*>(c)->newIdea("I like to sleep ");

            std::cout << std::endl << "COPY ASSIGNEMENT" << std::endl;
            *dynamic_cast<Cat*>(c2) = *dynamic_cast<Cat*>(c);
            std::cout << "ADRESSES:" << std::endl;
            std::cout << "c: " << dynamic_cast<Cat*>(c)->brain() << std::endl;
            std::cout << "c2: " << dynamic_cast<Cat*>(c2)->brain() << std::endl;

            std::cout << "IDEAS" << std::endl;
            dynamic_cast<Cat*>(c)->tellIdea();
            dynamic_cast<Cat*>(c2)->tellIdea();


            std::cout << std::endl << "COPY CONSTRUCTOR" << std::endl;
            Cat *c_copy = new Cat(* dynamic_cast<Cat*>(c));

            std::cout << "ADRESSES:" << std::endl;
            std::cout << "c: " << dynamic_cast<Cat*>(c)->brain() << std::endl;
            std::cout << "c_copy: " << dynamic_cast<Cat*>(c_copy)->brain() << std::endl;

            std::cout << "IDEAS" << std::endl;
            dynamic_cast<Cat*>(c)->tellIdea();
            dynamic_cast<Cat*>(c_copy)->tellIdea();

            std::cout << std::endl << "DESTRUCTION" << std::endl;
            delete c;
            delete c2;
            delete c_copy;
        } 
        catch (const std::bad_alloc& e) 
        {
            std::cerr << "Allocation failed: " << e.what() << std::endl;
        }
}