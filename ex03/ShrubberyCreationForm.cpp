#include "ShrubberyCreationForm.hpp"
#include <fstream>

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreation", 145, 137), target("Default") {}

// Parameterized constructor
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreation", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    : AForm(other), target(other.target) {}

// Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other) {
        AForm::operator=(other);
        this->target = other.target;
    }
    return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

// Action method
void ShrubberyCreationForm::action() const {
    std::ofstream file((this->target + "_shrubbery").c_str());
    if (file.is_open()) {
        file << "         v" << std::endl;
        file << "        >X<" << std::endl;
        file << "         A" << std::endl;
        file << "        d$b" << std::endl;
        file << "      .d\\$$b." << std::endl;
        file << "    .d$i$$\\$$b." << std::endl;
        file << "       d$$@b" << std::endl;
        file << "      d\\$$$ib" << std::endl;
        file << "    .d$$$\\$$$b" << std::endl;
        file << "  .d$$@$$$$\\$$ib." << std::endl;
        file << "      d$$i$$b" << std::endl;
        file << "     d\\$$$$@$b" << std::endl;
        file << "  .d$@$$\\$$$$$@b." << std::endl;
        file << ".d$$$$i$$$\\$$$$$$b." << std::endl;
        file << "        ###" << std::endl;
        file << "        ###" << std::endl;
        file << "        ###" << std::endl;
        file.close();
    } else {
        throw std::runtime_error("Unable to create file");
    }
}