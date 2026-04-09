#include "../HEADER/Intern.hpp"
#include "../HEADER/PresidentialPardonForm.hpp"
#include "../HEADER/RobotomyRequestForm.hpp"
#include "../HEADER/ShrubberyCreationForm.hpp"
#include <iostream>

using FormCreatorFunc = AForm* (Intern::*)(const std::string&);

Intern::Intern()
{
    this->_formNames[0] = "shrubbery creation";
    this->_formNames[1] = "robotomy request";
    this->_formNames[2] = "presidential pardon";
}

Intern::~Intern()
{
    
}

Intern::Intern(const Intern &other)
{
    for (int i = 0; i < 3; i++)
    {
        this->_formNames[i] = other._formNames[i];
    }      
}

Intern &Intern::operator=(const Intern &other)
{
    if (this != &other)
    {
        for (int i = 0; i < 3; i++)
        {
            this->_formNames[i] = other._formNames[i];
        }      
    }
    return (*this);
}

const char* Intern::FormNotFoundException::what() const noexcept
{
    return "Error : Form not found.";
}

AForm* Intern::makeShrubbery(const std::string& target)
{
    std::cout << "Intern creates ShrubberyCreationForm for " << target << std::endl;
    return new ShrubberyCreationForm(target);
}
AForm* Intern::makeRobotomy(const std::string& target)
{
    std::cout << "Intern creates RobotomyRequestForm for " << target << std::endl;
    return new RobotomyRequestForm(target);
}
AForm* Intern::makePresidential(const std::string& target)
{
    std::cout << "Intern creates PresidentialPardonForm for " << target << std::endl;
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
    FormCreatorFunc creators[3] =
    {
        &Intern::makeShrubbery,
        &Intern::makeRobotomy,
        &Intern::makePresidential
    };
    for (int i = 0; i < 3; i++)
    {
        if (formName == this->_formNames[i])
            return (this->*creators[i])(target);
    }
    throw Intern::FormNotFoundException();
}