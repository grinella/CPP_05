#pragma once

#include <iostream>
#include <string>

// Forward declaration
class Bureaucrat;

class AForm {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

protected:
    virtual void action() const = 0; // Pure virtual function

public:
    // Orthodox Canonical Form
    AForm();
    AForm(const std::string &name, int signGrade, int execGrade);
    AForm(const AForm &other);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    void beSigned(const Bureaucrat &b);
    void execute(const Bureaucrat &executor) const;

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };
    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };
    class FormNotSignedException : public std::exception {
        const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &form);