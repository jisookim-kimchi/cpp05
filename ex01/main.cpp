/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:50:28 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:50:29 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HEADER/Form.hpp"
#include <iostream>

int main()
{
    Bureaucrat *kimchi = new Bureaucrat("kimchi", 5);
    //Bureaucrat *haribo = new Bureaucrat("haribo", 15);
    Form *A = new Form("A", 10, 10);
    Form *B = new Form("B", 151, 151);
    (void)B;
    A->beSigned(*kimchi);
    //A->beSigned(*haribo);
    std::cout << A->getIssign() << std::endl;
    delete A;
    delete B;
    delete kimchi;

    return 0;
}