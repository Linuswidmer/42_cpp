# include "Test.hpp"

int main()
{
	try
    {
        Test a = Test("karl", 2);
        // throw Test::TestException();
    }  
    catch(Test e)
    {
        std::cout << "Test caught" << std::endl;
        // std::cout << e.what() << std::endl;
    }
    catch (char *e)
    {
        std::cout << "caught a star" << std::endl;
    }
    catch (std::exception& e)
    {
    	std::cout << "Exception caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
}