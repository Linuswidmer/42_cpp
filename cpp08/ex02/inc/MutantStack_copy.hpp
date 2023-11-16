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
    Iterator begin(void) const;
    Iterator end(void) const;

    class Iterator {
    public:
    
        // Operator Overloading
        Iterator& operator++(void);
        Iterator operator++(int);
        bool operator==(const Iterator& other) const;
        bool operator!=(const Iterator& other) const;
        T& operator*();

    
        // Constructors, Assignment, Destructors
        Iterator(void);
        Iterator(const Iterator &copy);
        Iterator &operator=(const Iterator &other);
        ~Iterator();

    private:
        typename std::deque<T>::iterator iter; // why do I need a typename here?

    };
private:
    std::deque<T> _deq;
};

/*****************************************************************************/
/*                                 ITERATOR                                  */
/*****************************************************************************/

/*-------------------------- OPERATOR OVERLOADING ---------------------------*/

template <typename T>
typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator++() 
{
    ++iter;
    return *this;
}

template <typename T>
typename MutantStack<T>::Iterator MutantStack<T>::Iterator::operator++(int) 
{
    Iterator temp = *this;
    ++(*this);
    return temp;
}

template <typename T>
bool    MutantStack<T>::Iterator::operator==(const Iterator &other) const 
{
    return current == other.current;
}

template <typename T>
bool    MutantStack<T>::Iterator::operator==(const Iterator &other) const 
{
    return !(*this == other);
}

template <typename T>
bool    MutantStack<T>::Iterator::operator==(const Iterator &other) const 
{
    return (*current);
}

/*------------------- CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR ------------------*/
template <typename T>
MutantStack<T>::Iterator::Iterator() 
    : iter()
{
}

template <typename T>
MutantStack<T>::Iterator::Iterator(const Iterator &copy)
{
    *this = copy;
}

template <typename T>
MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator=(const Iterator &other)
{
    if (this != &other)
    {
        iter = other.iter;
    }
    return (*this);
}

template <typename T>
MutantStack<T>::Iterator::~Iterator() 
{
}


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
    _deq.insert(value);
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

template <typename T>    MutantStack::begin()
{
    return ()
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