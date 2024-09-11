#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default constructor
AForm::AForm() : name("Default"), isSigned(false), signGrade(150), execGrade(150) {}

// Parameterized constructor
AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name(name), isSigned(false), signGrade(signGrade), execGrade(execGrade) {
    if (signGrade < 1 || execGrade < 1) throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150) throw GradeTooLowException();
}

// Copy constructor
AForm::AForm(const AForm &other)
    : name(other.name), isSigned(other.isSigned), signGrade(other.signGrade), execGrade(other.execGrade) {}

// Copy assignment operator
AForm &AForm::operator=(const AForm &other) {
    if (this != &other) {
        this->isSigned = other.isSigned;
    }
    return *this;
}

// Destructor
AForm::~AForm() {}

// Getter methods
std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return isSigned; }
int AForm::getSignGrade() const { return signGrade; }
int AForm::getExecGrade() const { return execGrade; }

// Method to sign the form
void AForm::beSigned(const Bureaucrat &b) {
    if (b.getGrade() > signGrade) throw GradeTooLowException();
    isSigned = true;
}

// Execute method
void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->getExecGrade())
        throw GradeTooLowException();
    this->action(); // Chiama l'azione specifica del form
}

// Exception messages
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

const char* AForm::FormNotSignedException::what() const throw() {
    return "Form is not signed!";
}

// Overload of the output stream operator
std::ostream &operator<<(std::ostream &out, const AForm &form) {
    out << "Form " << form.getName() << ", signed: " << form.getIsSigned()
        << ", required sign grade: " << form.getSignGrade()
        << ", required execute grade: " << form.getExecGrade();
    return out;
}