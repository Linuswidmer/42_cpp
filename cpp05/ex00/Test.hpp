# include <string>
# include <iostream>
# include <exception>

class Test: std::exception
{
public:
    Test();
    ~Test() throw();
    std::exception    TestException(void);
    Test(const std::string& name, int grade);
    
    // static std::exception    TestException(void);

private:
    std::string _name;
    int         _grade;
    static const int _exception = 8;
};


std::exception    Test::TestException(void)
{
    std::cout << "Grade too high" << std::endl;
    return (std::exception());
}

// std::exception Test::TestException(void)
// {
//     return (std::runtime_error("Grade too high"));
// }

Test::Test(const std::string& name, int grade)
{
    std::cout << "constructor called" << std::endl;
    if (grade > 1)
        throw(this->TestException());
}

Test::~Test() throw()
{}

Test::Test(void)
{}