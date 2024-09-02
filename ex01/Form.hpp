#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form {
private:
    const std::string name;
    bool isSigned;
    const int signGrade;
    const int execGrade;

public:
    // Orthodox Canonical Form
    Form(); // Default constructor
    Form(const std::string &name, int signGrade, int execGrade); // Parameterized constructor
    Form(const Form &other); // Copy constructor
    Form &operator=(const Form &other); // Copy assignment operator
    ~Form(); // Destructor

    // Getter methods
    std::string getName() const;
    bool getIsSigned() const;
    int getSignGrade() const;
    int getExecGrade() const;

    // Method to sign the form
    void beSigned(const Bureaucrat &b);

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
std::ostream& operator<<(std::ostream &out, const Form &f);