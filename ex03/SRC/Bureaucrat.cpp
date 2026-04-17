/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:52:18 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:52:19 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/Bureaucrat.hpp"
#include <iostream>
#include "../HEADER/AForm.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
    
}

Bureaucrat::Bureaucrat(const std::string name, int grade) :_name(name), _grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :_name(other.getName()), _grade(other.getGrade())
{
    
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this != &other)
    {
        this->_grade = other.getGrade();
    }
    return (*this);
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

void Bureaucrat::incrementGrade()
{
    if (this->_grade < 2)
        throw Bureaucrat::GradeTooHighException();
    this->_grade--;
}

void Bureaucrat::decrementGrade()
{
    if (this->_grade > 149)
        throw Bureaucrat::GradeTooLowException();
    this->_grade++;
}


std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
    output << bureaucrat.getName() << " " << bureaucrat.getGrade() << std::endl;
    return (output);
}

const std::string &Bureaucrat::getName() const
{
    return (this->_name);
}

int Bureaucrat::getGrade() const
{
    return (this->_grade);
}

void Bureaucrat::signForm(AForm &form)
{
   try
   {
    form.beSigned(*this);
   }
   catch (AForm::GradeTooLowException &except)
   {
    std::cerr << getName() << " couldn't sign " << form.getName()  << " because " << except.what() << std::endl;
    return ;
   }
   std::cout << getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm &form)
{
    try
    {
        form.execute(*this);
    }
    catch (AForm::GradeTooLowException &except)
    {
        std::cerr << getName() << " couldn't execute " << form.getName()  << " because " << except.what() << std::endl;
        return ;
    }
    std::cout << getName() << " executed " << form.getName() << std::endl;
}