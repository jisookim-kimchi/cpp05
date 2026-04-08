#include "AForm.hpp"
#include <iostream>

AForm::AForm() : _name("default"), _issign(false), _grade_to_sign(150), _grade_to_execute(150)
{
   
}

AForm::AForm(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _issign(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw AForm::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw AForm::GradeTooLowException();
}

AForm::~AForm()
{
    
}

AForm::AForm(const AForm &other) : _name(other.getName()), _issign(other.getIssign()), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute())
{

}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->_issign = other.getIssign();
    }
    return (*this);
}

const std::string &AForm::getName() const
{
    return this->_name;
}

const bool &AForm::getIssign() const
{
    return this->_issign;
}

const int &AForm::getGradeToSign() const
{
    return this->_grade_to_sign;
}

const int &AForm::getGradeToExecute() const
{
    return this->_grade_to_execute;
}

const char* AForm::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

const char* AForm::NotSignedException::what() const noexcept
{
    return "The form is not signed!";
}

std::ostream &operator<<(std::ostream &output, const AForm &aform)
{
    output << aform.getName() << " " << aform.getGradeToSign() << " " << aform.getGradeToExecute() << std::endl;
    return (output);
}

void AForm::check(const Bureaucrat &executor) const
{
    if (this->getIssign() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() > this->getGradeToExecute())
        throw AForm::GradeTooLowException();
}

void AForm::execute(const Bureaucrat &executor) const
{
    check(executor);
    action();
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_grade_to_sign)
        throw AForm::GradeTooLowException();
    this->_issign = true;
}

