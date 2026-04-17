/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:51:17 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:51:18 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HEADER/AForm.hpp"
#include "HEADER/PresidentialPardonForm.hpp"
#include "HEADER/ShrubberyCreationForm.hpp"
#include "HEADER/RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat *boss = new Bureaucrat("boss", 1);
    Bureaucrat *employee = new Bureaucrat("employee", 30);

    PresidentialPardonForm *kimchi =  new PresidentialPardonForm("kimchi");
    RobotomyRequestForm *haribo = new RobotomyRequestForm("haribo");
    ShrubberyCreationForm *currywurst = new ShrubberyCreationForm("currywurst");

    boss->signForm(*kimchi);
    //employee->signForm(*kimchi);
    employee->signForm(*haribo);
    employee->signForm(*currywurst);
    
    boss->executeForm(*kimchi);
    boss->executeForm(*haribo);
    boss->executeForm(*currywurst);

    delete kimchi;
    delete haribo;
    delete currywurst;
    delete boss;
    delete employee;
    
    return 0;
}