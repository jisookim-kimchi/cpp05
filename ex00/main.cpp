#include "HEADER/Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat kimchi("kimchi", 0);
        std::cout << kimchi.getName() << " " << kimchi.getGrade() << std::endl; //skip...
    }
    catch (const Bureaucrat::GradeTooHighException &except)
    {
        std::cerr << except.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &except)
    {
        std::cerr << except.what() << std::endl;
    }

    Bureaucrat kimchi("kimchi", 150);
    for (int i = 0; i < 150; i++)
    {
        std::cout << i << std::endl;
        kimchi.incrementGrade();
    }

    return 0;
}