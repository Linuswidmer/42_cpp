#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
public:
    // public methods
    AForm    *makeForm(std::string form_name, std::string target);

    // Constructors, Assignment, Destructors
    Intern(void);
    Intern(const Intern& copy);
    Intern& operator=(const Intern& other);
    ~Intern(void);

private:
    class FormDoesNotExistException: public std::exception
    {
    public:
        const char *what () const throw();
    };
};

#endif