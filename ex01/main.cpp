#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        Form f1("Tax Return", 50, 25);
        b1.signForm(f1); // Alice firma il form
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 100);
        Form f2("Confidential Report", 50, 25);
        b2.signForm(f2); // Bob dovrebbe fallire nel firmare
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}