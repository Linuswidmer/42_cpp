#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>
# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
public:
    // public methods
    void    execute(const Bureaucrat& executer) const;

    //Getters and Setters

    // Constructors, Assignment, Destructors
    PresidentialPardonForm(void);
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm& copy);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
    ~PresidentialPardonForm(void);

private:
    // Data
    std::string _target;
};

std::ostream& operator<<(std::ostream& o, PresidentialPardonForm const rhs);

#endif