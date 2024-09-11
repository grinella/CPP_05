#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
private:
    std::string target;

protected:
    void action() const;

public:
    // Orthodox Canonical Form
    PresidentialPardonForm();
    PresidentialPardonForm(const std::string &target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
};