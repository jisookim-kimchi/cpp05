/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jisokim2 <jisokim2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/17 11:50:16 by jisokim2          #+#    #+#             */
/*   Updated: 2026/04/17 11:50:17 by jisokim2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Form
{
public:
    Form();
    Form(const std::string name, int grade_to_sign, int grade_to_execute);
    ~Form();
    Form(const Form &other);
    Form &operator=(const Form &other);

    const std::string &getName() const;
    const bool &getIssign() const;
    const int &getGradeToSign() const;
    const int &getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    
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
    bool _issign;
    const int _grade_to_sign;
    const int _grade_to_execute;
};

#endif