#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default constructor
Form::Form() : name("Default"), isSigned(false), signGrade(150), execGrade(150) {}

// Parameterized constructor
Form::Form(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) {
        throw GradeTooHighException();
    }
    if (signGrade > 150 || execGrade > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Form::Form(const Form &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

// Copy assignment operator
Form &Form::operator=(const Form &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
Form::~Form() {}

// Getter methods
std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return isSigned; }
int Form::getSignGrade() const { return signGrade; }
int Form::getExecGrade() const { return execGrade; }

// Method to sign the form
void Form::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > signGrade) {
        throw GradeTooLowException();
    }
    isSigned = true;
}

// GradeTooHighException message
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high for the form!";
}

// GradeTooLowException message
const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low for the form!";
}

// Overload of the output stream operator
std::ostream& operator<<(std::ostream &out, const Form &f) {
    out << "Form " << f.getName() << ", signed: " << f.getIsSigned()
        << ", required sign grade: " << f.getSignGrade()
        << ", required execute grade: " << f.getExecGrade();
    return out;
}