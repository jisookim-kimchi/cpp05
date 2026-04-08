#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <exception>
#include "Bureaucrat.hpp"

class AForm
{
public:
    AForm();
    AForm(const std::string name, int grade_to_sign, int grade_to_execute);
    virtual ~AForm();
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);

    const std::string &getName() const;
    const bool &getIssign() const;
    const int &getGradeToSign() const;
    const int &getGradeToExecute() const;
    void beSigned(const Bureaucrat &bureaucrat);
    void execute(const Bureaucrat &executor) const;

    // virtual void action() const = 0;
    // void check(const Bureaucrat &executor) const;
    
    class NotSignedException : public std::exception
    {
        public:
            const char* what() const noexcept override;
    };

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
    virtual void action() const = 0;
    void check(const Bureaucrat &executor) const;
    const std::string _name;
    bool _issign;
    const int _grade_to_sign;
    const int _grade_to_execute;
};

#endif