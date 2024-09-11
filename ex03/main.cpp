#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    try {
        Intern someRandomIntern;
        Bureaucrat highRank("CEO", 1);

        AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            highRank.signForm(*rrf);
            highRank.executeForm(*rrf);
            delete rrf;
        }

        AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (scf) {
            highRank.signForm(*scf);
            highRank.executeForm(*scf);
            delete scf;
        }

        AForm* ppf = someRandomIntern.makeForm("presidential pardon", "John Doe");
        if (ppf) {
            highRank.signForm(*ppf);
            highRank.executeForm(*ppf);
            delete ppf;
        }

        // Test with an unknown form
        AForm* unknown = someRandomIntern.makeForm("unknown form", "Target");
        if (unknown) {
            delete unknown;
        }
    }
    catch (std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    return 0;
}