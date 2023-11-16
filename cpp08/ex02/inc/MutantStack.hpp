#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <deque>

template <typename T>
class MutantStack
{
public:
    // public methods
    T       top(void) const;
    void    push(const &T);
    void    pop(void);
    bool    empty(void) const;
    size_type size(void) const;

    // Constructors, Assignment, Destructors
    MutantStack(void);
    MutantStack(const MutantStack& copy);
    MutantStack& operator=(const MutantStack& other);
    ~MutantStack(void);

    // Operator overloading
    T& operator[](unsigned int idx);

private:
    // Data
    std::deque<T> _deq;
};

template <typename T>
MutantStack<T>::MutantStack(void)
{
}
template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{

}
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{

}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}

template <typename T>
T& MutantStack<T>::operator[](unsigned int idx)
{
    
}

#endif