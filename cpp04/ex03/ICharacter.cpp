# include "header.h"

ICharacter::~ICharacter()
{
    if (DEBUG)
        std::cout << "ICharacter: Destructor called" << std::endl;
}