#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

void displayMenu() {
    std::cout << "Options:\n";
    std::cout << "1. Enter a fraction manually\n";
    std::cout << "2. Add a fraction\n";
    std::cout << "3. Subtract a fraction\n";
    std::cout << "4. Multiply by a fraction\n";
    std::cout << "5. Divide by a fraction\n";
    std::cout << "6. Display as Mixed Fraction\n";
    std::cout << "7. Clear Fraction\n";
    std::cout << "8. Exit\n";
}

int main() {
    Fraction currentFraction;

    while (true) {
        std::cout << "Current Fraction: " << currentFraction << std::endl;
        displayMenu();
        int choice;
        std::cin >> choice;

        if (choice == 8) break;

        if (choice == 1) {
            int num, den;
            std::cout << "Enter numerator and denominator: ";
            std::cin >> num >> den;
            currentFraction = Fraction(num, den);
        } else if (choice >= 2 && choice <= 5) {
            int num, den;
            std::cout << "Enter numerator and denominator: ";
            std::cin >> num >> den;
            Fraction other(num, den);

            if (choice == 2) currentFraction = currentFraction + other;
            else if (choice == 3) currentFraction = currentFraction - other;
            else if (choice == 4) currentFraction = currentFraction * other;
            else if (choice == 5) currentFraction = currentFraction / other;
        } else if (choice == 6) {
            MixedFraction mixed(currentFraction);
            std::cout << "Mixed Fraction: " << mixed << std::endl;
        } else if (choice == 7) {
            currentFraction = Fraction();
        }
    }
    return 0;
}

