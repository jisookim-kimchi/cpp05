
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <exception>

class AForm;

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
    void signForm(AForm &form);
    
    void executeForm(AForm &form);

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