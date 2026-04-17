/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:51:11 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:51:12 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADER/ShrubberyCreationForm.hpp"
#include <fstream>
#include <cerrno>
#include <cstring>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default")
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target)
{
	
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	
}

void ShrubberyCreationForm::action() const
{
    std::ofstream outFile((_target + std::string("_shrubbery")).c_str());

	if (outFile)
	{
		outFile << "    /\\    \n";
		outFile << "   /  \\   \n";
		outFile << "  /    \\  \n";
		outFile << " /      \\ \n";
		outFile << "/________\\\n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";
		outFile << "    ||    \n";

		outFile.close();
	}
	else
		throw ShrubberyCreationForm::OpenFileError();
}

const char *ShrubberyCreationForm::OpenFileError::what() const noexcept
{
    return std::strerror(errno);
}

const std::string &ShrubberyCreationForm::getTarget() const
{
    return (_target);
}