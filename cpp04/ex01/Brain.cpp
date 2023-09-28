# include "Brain.hpp"

const std::string  Brain::getIdea(size_t i) const
{
    return (_ideas[i]);
}

size_t  Brain::index_ideas(void) const
{
    return (_index_ideas);
}

void    Brain::setIdea(const std::string idea)
{
    _ideas[_index_ideas % 100] = idea;
    _index_ideas++;
}

Brain::Brain(void)
    : _index_ideas(0)
{
    std::cout << "Brain: constructor called" << std::endl;
}

Brain::Brain(const Brain& copy)
    : _index_ideas(copy.index_ideas())
{
    std::cout << "Brain: Copy constructor called" << std::endl;
    for (size_t i = 0; i < _n_ideas; i++)
            this->_ideas[i] = copy._ideas[i];
}

Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain: Copy assignement called" << std::endl;
    _index_ideas = other.index_ideas();
    if (this != &other)
    {
        for (size_t i = 0; i < _n_ideas; i++)
            this->_ideas[i] = other.getIdea(i);
    }
    return (*this);
}

Brain::~Brain(void)
{
    cout << "Brain destructor called" << endl;
}