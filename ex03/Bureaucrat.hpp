#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

// Forward declaration
class AForm;

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Orthodox Canonical Form
    Bureaucrat(); 
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    std::string getName() const;
    int getGrade() const;

    void incrementGrade();
    void decrementGrade();

    // Methods involving AForm
    void signForm(AForm &form);
    void executeForm(const AForm &form) const;  // Aggiungi la dichiarazione

    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);