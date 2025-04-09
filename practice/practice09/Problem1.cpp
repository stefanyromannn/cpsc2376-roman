#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f}; 
    float bluePotion{0.0f};
    float* flask{nullptr};
    std::string choice;

    while (true) {
        std::cout << "Pick your posion.. (Red, Blue, or Done):";
        std::cin >> choice;

        if (choice == "Done") {
            break;
        }

        if (choice == "Red") {
            flask = &redPotion;
        } else if (choice == "Blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Couldn't find that one. Try again \n";
            continue;
        }

        float amount;
        std::cout << "How many mL do you want to add? ";
        std::cin >> amount;

        if (flask != nullptr) {
            *flask += amount;
        }

        std::cout << "Current potion level:\n";
        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n\n";
    }

    std::cout << "We are done witches.\n";
    return 0;
}
