#include "Serialize.hpp"

/*------------------PUBLIC METHODS -----------------*/

uintptr_t    Serialize::serialize(Data *ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*   Serialize::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data *>(raw));
}

/*----------------GETTERS AND SETTERS --------------*/

Serialize&  Serialize::get(void)
{
    static  Serialize   S_Instance;
    return(S_Instance);
}

/*-----------CONSTRUCTOR, ASSIGNEMENT, DESTRUCTOR------ */

Serialize::Serialize(void)
{}

Serialize::Serialize(const Serialize& copy)
{
    (void) copy;
}

Serialize& Serialize::operator=(const Serialize& other)
{
    if (this != &other)
    {}
    return (*this);
}

Serialize::~Serialize(void)
{}

/* ----------------OPERATOR OVERLOAD---------------*/