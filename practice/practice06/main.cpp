#include <iostream>
#include "Fraction.h"
#include "MixedFraction.h"

using namespace std;

void displayMenu() {
    cout << "Options:\n";
    cout << "1. Enter a fraction manually\n";
    cout << "2. Add a fraction\n";
    cout << "3. Subtract a fraction\n";
    cout << "4. Multiply by a fraction\n";
    cout << "5. Divide by a fraction\n";
    cout << "6. Display as Mixed Fraction\n";
    cout << "7. Clear Fraction\n";
    cout << "8. Exit\n";
}

int main() {
    Fraction currentFraction;

    while (true) {
        cout << "Current Fraction: " << currentFraction << endl;
        displayMenu();
        int choice;
        cin >> choice;

        if (choice == 8) break;

        if (choice == 1) {
            int num, den;
            cout << "Enter numerator and denominator: ";
            cin >> num >> den;
            currentFraction = Fraction(num, den);
        } else if (choice >= 2 && choice <= 5) {
            int num, den;
            cout << "Enter numerator and denominator: ";
            cin >> num >> den;
            Fraction other(num, den);

            if (choice == 2) currentFraction = currentFraction + other;
            else if (choice == 3) currentFraction = currentFraction - other;
            else if (choice == 4) currentFraction = currentFraction * other;
            else if (choice == 5) currentFraction = currentFraction / other;
        } else if (choice == 6) {
            MixedFraction mixed(currentFraction);
            cout << "Mixed Fraction: " << mixed << endl;
        } else if (choice == 7) {
            currentFraction = Fraction();
        }
    }
    return 0;
}
