#ifndef CURE_HPP
# define CURE_HPP

# include "header.h"

class Cure: public AMateria
{
public:
    Cure(void);
    Cure(const Cure& copy);
    Cure &operator=(const Cure& other);
    ~Cure(void);

    AMateria*   clone() const; // override
    void        use(ICharacter& target); // override
private:
};

#endif