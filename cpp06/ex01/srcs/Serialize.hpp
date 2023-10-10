#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <string>
# include "header.h"
# include <stdint.h>

class Serialize
{
public:
    // public methods
    static uintptr_t    serialize(Data *ptr);
    static Data*        deserialize(uintptr_t raw);

    //Getters and Setters
    static Serialize&   get(void);

private:
    // Constructors, Assignment, Destructors
    Serialize(void);
    Serialize(const Serialize& copy);
    Serialize& operator=(const Serialize& other);
    ~Serialize(void);
};

#endif