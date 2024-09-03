#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
private:
    std::string target;

protected:
    void action() const;

public:
    // Orthodox Canonical Form
    ShrubberyCreationForm();
    ShrubberyCreationForm(const std::string &target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();
};