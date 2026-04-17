/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:50:28 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 12:35:04 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HEADER/Form.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat *kimchi = new Bureaucrat("kimchi", 5);
        Form *A = new Form("A", 10, 10);

        Form B("B", 151, 151); // will throw here

        A->beSigned(*kimchi);
        std::cout << A->getIssign() << std::endl;

        delete A;
        delete kimchi;
    }
    catch (const std::exception &e) //catches all exceptions derived from std::exception
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}