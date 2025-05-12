#include <iostream>
#include <memory>
#include "TextProcessor.h"
#include "ReverseFilter.h"
#include "UppercaseFilter.h"
#include "RemoveVowelsFilter.h"
#include "CensorBadWordsFilter.h"

int main() {
    TextProcessor processor;
    std::string input;

    std::cout << "Enter a sentence: ";
    std::getline(std::cin, input);

    while (true) {
        std::cout << "\nChoose a filter strategy:\n";
        std::cout << "1. Reverse\n";
        std::cout << "2. Uppercase\n";
        std::cout << "3. Remove Vowels\n";
        std::cout << "4. Censor Bad Words\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline left in the input buffer

        if (choice == 1) {
            processor.setFilter(std::make_shared<ReverseFilter>());
        } else if (choice == 2) {
            processor.setFilter(std::make_shared<UppercaseFilter>());
        } else if (choice == 3) {
            processor.setFilter(std::make_shared<RemoveVowelsFilter>());
        } else if (choice == 4) {
            processor.setFilter(std::make_shared<CensorBadWordsFilter>());
        } else if (choice == 5) {
            break; // Exit the loop
        } else {
            std::cout << "Invalid choice. Try again.\n";
            continue;
        }

        processor.applyFilter(input);
    }

    return 0;
}
