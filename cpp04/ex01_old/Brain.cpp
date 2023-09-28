# include "Brain.hpp"

string  Brain::getIdea(void) const
{
    return (_ideas[0]);
}

void    Brain::setIdea(const string idea)
{
    _ideas[0] = idea;
}

Brain::Brain(void)
{
    std::cout << "Brain: constructor called" << endl;
}

Brain::Brain(const Brain& copy)
{
    cout << "Brain: Copy constructor called" << endl;
    (void)copy;
}

Brain& Brain::operator=(const Brain& other)
{
    cout << "Brain: Copy assignement called" << endl;
    if (this != &other) 
    {
        for (size_t i = 0; i < _n_ideas; i++)
            this->_ideas[i] = other._ideas[i];
    }
    return (*this);
}

Brain::~Brain(void)
{
    cout << "Brain destructor called" << endl;
}