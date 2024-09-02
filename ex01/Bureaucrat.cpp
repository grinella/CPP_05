#include "Bureaucrat.hpp"
#include "Form.hpp" 

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name), grade(grade) {
    if (grade < 1) {
        throw GradeTooHighException();
    }
    if (grade > 150) {
        throw GradeTooLowException();
    }
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

// Copy assignment operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
    if (this != &other) {
        this->grade = other.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

// Getter for name
std::string Bureaucrat::getName() const {
    return name;
}

// Getter for grade
int Bureaucrat::getGrade() const {
    return grade;
}

// Increment grade
void Bureaucrat::incrementGrade() {
    if (grade <= 1) {
        throw GradeTooHighException();
    }
    --grade;
}

// Decrement grade
void Bureaucrat::decrementGrade() {
    if (grade >= 150) {
        throw GradeTooLowException();
    }
    ++grade;
}

// signForm method implementation
void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;
    } catch (const std::exception &e) {
        std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

// GradeTooHighException message
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high!";
}

// GradeTooLowException message
const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low!";
}

// Overload of the output stream operator
std::ostream& operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade();
    return out;
}