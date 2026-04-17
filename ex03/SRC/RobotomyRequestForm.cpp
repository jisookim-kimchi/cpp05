/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:52:28 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:52:29 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default")
{

}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target)
{

}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return (*this);
}

void RobotomyRequestForm::action() const
{
    std::cout << "Ziiiiiiiiiiiiiiiing..." << std::endl;
    
    if (std::rand() % 2 == 0)
        std::cout << getTarget() << " has been robotomized successfully" << std::endl;
    else
        std::cout << getTarget() << "robotomy failed" << std::endl;
}

const std::string &RobotomyRequestForm::getTarget() const
{
    return (_target);
}