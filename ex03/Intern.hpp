#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	AForm *makeForm(const std::string &formName, const std::string &target);

    class FormNotFoundException : public std::exception
	{
    public:
        const char *what() const noexcept override;
    };
private:
	std::string _formNames[3];
    AForm *makeShrubbery(const std::string &target);
    AForm *makeRobotomy(const std::string &target);
    AForm *makePresidential(const std::string &target);
};

#endif