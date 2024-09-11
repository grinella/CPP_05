#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequest", 72, 45), target("Default") {}

// Parameterized constructor
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequest", 72, 45), target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    : AForm(other), target(other.target) {}

// Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

// Action method
void RobotomyRequestForm::action() const {
    std::srand(std::time(0));
    std::cout << "* Drilling noises *" << std::endl;
    if (std::rand() % 2) {
        std::cout << target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy failed on " << target << "!" << std::endl;
    }
}