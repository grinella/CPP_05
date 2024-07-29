#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        Bureaucrat b1("Alice", 1);
        std::cout << b1 << std::endl;
        b1.incrementGrade(); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b2("Bob", 151); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat b3("Charlie", 150);
        std::cout << b3 << std::endl;
        b3.decrementGrade(); // This should throw an exception
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}