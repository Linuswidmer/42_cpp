#ifndef AMATERIA_HPP
# define AMATERIA_HPP
#include "header.h"

class AMateria
{
protected:
    std::string _type;
// [...]
public:
    AMateria(std::string const & type);
    AMateria(const AMateria& copy);
    virtual ~AMateria(void);

    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    // virtual void use(ICharacter& target);

    std::string type(void) const;
};
# endif