/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:52:34 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 12:29:44 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HEADER/AForm.hpp"
#include "HEADER/PresidentialPardonForm.hpp"
#include "HEADER/ShrubberyCreationForm.hpp"
#include "HEADER/RobotomyRequestForm.hpp"
#include "HEADER/Intern.hpp"

int main()
{
    Bureaucrat *boss = new Bureaucrat("boss", 1);
    Bureaucrat *employee = new Bureaucrat("employee", 30);
    Intern *intern = new Intern();

    AForm *a1 = NULL;
    AForm *a2 = NULL;
    AForm *a3 = NULL;
    AForm *a4 = NULL;

    try
    {
        a1 = intern->makeForm("ShrubberyCreationForm", "currywurst");
        a2 = intern->makeForm("RobotomyRequestForm", "haribo");
        a3 = intern->makeForm("PresidentialPardonForm", "kimchi");
        a4 = intern->makeForm("worng", "unknown");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Intern error: " << e.what() << std::endl;
    }

    std::cout << "---------------- TEST 1 ----------------" << std::endl;

    if (a1)
    {
        boss->signForm(*a1);
        employee->signForm(*a1);
        boss->executeForm(*a1);
        employee->executeForm(*a1);
    }

    std::cout << "---------------- TEST 2 ----------------" << std::endl;
    
    if (a2)
    {
        boss->signForm(*a2);
        employee->signForm(*a2);
        boss->executeForm(*a2);
        employee->executeForm(*a2);
    }

    std::cout << "---------------- TEST 3 ----------------" << std::endl;
    
    if (a3)
    {
        boss->signForm(*a3);
        employee->signForm(*a3);
        boss->executeForm(*a3);
        employee->executeForm(*a3);
    }

    std::cout << "---------------- CLEANUP! ----------------" << std::endl;

    delete a1;
    delete a2;
    delete a3;
    delete a4;
    delete intern;
    delete boss;
    delete employee;

    return 0;
}