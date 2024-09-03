#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        // Test Bureaucrat
        Bureaucrat lowRank("Intern", 150);
        Bureaucrat midRank("Manager", 50);
        Bureaucrat highRank("CEO", 1);

        std::cout << lowRank << std::endl;
        std::cout << midRank << std::endl;
        std::cout << highRank << std::endl;

        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubForm("home");
        std::cout << shrubForm << std::endl;

        lowRank.signForm(shrubForm);  // Should fail
        midRank.signForm(shrubForm);  // Should succeed
        lowRank.executeForm(shrubForm);  // Should fail (not signed)
        midRank.executeForm(shrubForm);  // Should succeed

        // Test RobotomyRequestForm
        RobotomyRequestForm robotForm("Bender");
        std::cout << robotForm << std::endl;

        midRank.signForm(robotForm);  // Should succeed
        midRank.executeForm(robotForm);  // Should fail (grade too low)
        highRank.executeForm(robotForm);  // Should succeed

        // Test PresidentialPardonForm
        PresidentialPardonForm pardonForm("Ford Prefect");
        std::cout << pardonForm << std::endl;

        midRank.signForm(pardonForm);  // Should fail
        highRank.signForm(pardonForm);  // Should succeed
        midRank.executeForm(pardonForm);  // Should fail
        highRank.executeForm(pardonForm);  // Should succeed

        // Test executing unsigned form
        ShrubberyCreationForm unsignedForm("garden");
        highRank.executeForm(unsignedForm);  // Should fail (not signed)

        // Test grade limits
        Bureaucrat tooHigh("Too High", 0);  // Should throw exception
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}