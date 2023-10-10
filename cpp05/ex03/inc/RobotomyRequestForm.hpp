#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <string>
# include <cstdlib> // for std::rand
# include <ctime> // for randomization of std::srand
# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
public:
    // public methods
    void    execute(const Bureaucrat& executer) const;

    // Constructors, Assignment, Destructors
    RobotomyRequestForm(void);
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
    ~RobotomyRequestForm(void);

private:
    // Data
    std::string _target;
};

std::ostream& operator<<(std::ostream& o, RobotomyRequestForm const rhs);

#endif