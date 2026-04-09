#include "../HEADER/Form.hpp"
#include <iostream>

Form::Form() : _name("default"), _issign(false), _grade_to_sign(150), _grade_to_execute(150)
{
}

Form::Form(const std::string name, int grade_to_sign, int grade_to_execute) : _name(name), _issign(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
    if (grade_to_sign < 1 || grade_to_execute < 1)
        throw Form::GradeTooHighException();
    if (grade_to_sign > 150 || grade_to_execute > 150)
        throw Form::GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other.getName()), _issign(other.getIssign()), _grade_to_sign(other.getGradeToSign()), _grade_to_execute(other.getGradeToExecute())
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->_issign = other.getIssign();
    }
    return (*this);
}

const std::string &Form::getName() const
{
    return this->_name;
}

const bool &Form::getIssign() const
{
    return this->_issign;
}

const int &Form::getGradeToSign() const
{
    return this->_grade_to_sign;
}

const int &Form::getGradeToExecute() const
{
    return this->_grade_to_execute;
}

const char *Form::GradeTooHighException::what() const noexcept
{
    return "Grade is too high!";
}

const char *Form::GradeTooLowException::what() const noexcept
{
    return "Grade is too low!";
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
    output << form.getName() << " " << form.getGradeToSign() << " " << form.getGradeToExecute() << std::endl;
    return (output);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->_grade_to_sign)
        throw Form::GradeTooLowException();
    this->_issign = true;
}
