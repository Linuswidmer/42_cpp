#include "header.h"

IMateriaSource::~IMateriaSource(void)
{
    if (DEBUG)
        std::cout << "IMateriaSource: Destructor called" << std::endl;
}