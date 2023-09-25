# include "Brain.hpp"

Brain::Brain(void)
{
    cout << "Brain constructor called" << endl;
}

Brain::Brain(const Brain& copy)
{
    cout << "Brain copy constructor called" << endl;
    // here I would need to copy the brains??
}

Brain& Brain::operator=(const Brain& other)
{
    cout << "Brain copy assignement called" << endl;
    if (this != &other) 
    {
        // ????
    }
}

Brain::~Brain(void)
{
    cout << "Brain destructor called" << endl;
}