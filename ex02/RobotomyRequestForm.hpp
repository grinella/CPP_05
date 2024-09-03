#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
private:
    std::string target;

protected:
    void action() const;

public:
    // Orthodox Canonical Form
    RobotomyRequestForm();
    RobotomyRequestForm(const std::string &target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
};