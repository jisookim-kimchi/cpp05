/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:51:17 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 12:40:35 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HEADER/AForm.hpp"
#include "HEADER/PresidentialPardonForm.hpp"
#include "HEADER/ShrubberyCreationForm.hpp"
#include "HEADER/RobotomyRequestForm.hpp"

int main()
{
    try
    {
        Bureaucrat boss("boss", 1);
        Bureaucrat employee("employee", 120);

        PresidentialPardonForm kimchi("kimchi");
        RobotomyRequestForm haribo("haribo");
        ShrubberyCreationForm currywurst("currywurst");

        boss.signForm(kimchi);        // should succeed
        employee.signForm(haribo);    // should fail
        employee.signForm(currywurst);

        boss.executeForm(kimchi);     // should succeed
        employee.executeForm(haribo); // should fail (not signed OR low grade)
        boss.executeForm(haribo);     // may succeed (if signed)
        boss.executeForm(currywurst); // should fail (not signed)

        try
        {
            Bureaucrat bad("bad", 0);
        }
        catch (const std::exception &e)
        {
            std::cout << "Caught Bureaucrat error: " << e.what() << std::endl;
        }
        try
        {
            Bureaucrat bad2("bad2", 200);
        }
        catch (const std::exception &e)
        {
            std::cout << "Caught Bureaucrat error: " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << "error: " << e.what() << std::endl;
    }

    return 0;
}