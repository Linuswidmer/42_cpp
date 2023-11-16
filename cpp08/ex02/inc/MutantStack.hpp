#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template <typename T>
class MutantStack
{
public:
    // public methods stack
    T       top(void) const;
    void    push(const T &value);
    void    pop(void);
    bool    empty(void) const;
    unsigned int size(void) const;

    // Constructors, Assignment, Destructors
    MutantStack(void);
    MutantStack(const MutantStack& copy);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack(void);

    // Iterator methods
    typename std::deque<T>::iterator begin(void);
    typename std::deque<T>::iterator end(void);

    typename std::deque<T>::iterator begin(void) const;
    typename std::deque<T>::iterator end(void) const;


    // Iterator
    typedef typename std::deque<T>::iterator iterator;
    typedef typename std::deque<T>::const_iterator const_iterator;

private:
    std::deque<T> _deq;
};

/*****************************************************************************/
/*                               MUTANT STACK                                */
/*****************************************************************************/

/*------------------------------ PUBLIC METHODS -----------------------------*/

template <typename T>
T   MutantStack<T>::top(void) const
{
    return (_deq.back());
}

template <typename T>
void MutantStack<T>::push(const T &value)
{
    _deq.push_back(value);
}

template <typename T>
void    MutantStack<T>::pop(void)
{
    _deq.erase(_deq.end());
}

template <typename T>
bool    MutantStack<T>::empty(void) const
{
    return(_deq.empty());
}

template <typename T>
unsigned int    MutantStack<T>::size(void) const
{
    return (_deq.size());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin()
{
    return (_deq.begin());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end()
{
    return (_deq.end());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin() const
{
    return (_deq.begin());
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end() const
{
    return (_deq.end());
}

/*------------------- CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR ------------------*/

template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
    *this = copy; 
}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
    {
        _deq = other._deq;
    }
    return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

#endif