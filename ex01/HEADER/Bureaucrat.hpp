/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:50:13 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:50:14 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class Form;

class Bureaucrat
{

public:
    Bureaucrat();
    Bureaucrat(const std::string name, int grade);
    ~Bureaucrat();
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    const std::string &getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    void signForm(Form &form);

    class GradeTooHighException : public std::exception
    {
    public:
        const char* what() const noexcept override;
    };

    class GradeTooLowException : public std::exception
    {
    public:
        const char* what() const noexcept override;
    };

private:
    const std::string _name;
    int _grade;
};

std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat);
#endif