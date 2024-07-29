#pragma once

#include <iostream>
#include <string>
#include <stdexcept>

class Bureaucrat {
private:
    const std::string name;
    int grade;

public:
    // Orthodox Canonical Form
    Bureaucrat(); // Default constructor
    Bureaucrat(const std::string &name, int grade); // Parameterized constructor
    Bureaucrat(const Bureaucrat &other); // Copy constructor
    Bureaucrat &operator=(const Bureaucrat &other); // Copy assignment operator
    ~Bureaucrat(); // Destructor

    // Getter for name and grade
    std::string getName() const;
    int getGrade() const;

    // Methods to increment and decrement the grade
    void incrementGrade();
    void decrementGrade();

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

// Overload of the output stream operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);