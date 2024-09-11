#include "Intern.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target) {
    static const std::string formNames[] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };

    static const FormCreator formCreators[] = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            AForm* form = (this->*formCreators[i])(target);
            std::cout << "Intern creates " << formName << std::endl;
            return form;
        }
    }

    std::cout << "Error: Unknown form name '" << formName << "'" << std::endl;
    return NULL;  // Changed from nullptr to NULL for C++98 compatibility
}