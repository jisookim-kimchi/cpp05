/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:49:59 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:50:00 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HEADER/Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat kimchi("kimchi", 0);
        std::cout << kimchi.getName() << " " << kimchi.getGrade() << std::endl; //skip...
    }
    catch (Bureaucrat::GradeTooHighException &except)
    {
        std::cerr << except.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException &except)
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