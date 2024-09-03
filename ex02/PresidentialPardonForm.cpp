#include "PresidentialPardonForm.hpp"
#include <iostream>

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardon", 25, 5), target("Default") {}

// Parameterized constructor
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardon", 25, 5), target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : AForm(other), target(other.target) {}

// Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

// Action method
void PresidentialPardonForm::action() const {
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}