#include <iostream>
#include <vector>

void printVector(const std::vector<int>& vec);
void doubleVector(std::vector<int>& vec);
int calculateSum(const std::vector<int>& vec);
void printMultiples(const std::vector<int>& vec, int num);

int main() {
    std::vector<int> numbers;
    int choice, value;

    do {
    std::cout << "\nMenu:\n";
    std::cout << "1. Add an item to the vector\n";
    std::cout << "2. Print the vector\n";
    std::cout << "3. Double the vector\n";
    std::cout << "4. Find the sum\n";
    std::cout << "5. Print multiples of a number\n";
    std::cout << "6. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    switch (choice) {
    case 1:
        std::cout << "Enter your number: ";
        std::cin >> value;
        numbers.push_back(value);
        break;

    case 2:
        printVector(numbers);
        break;

    case 3:
        doubleVector(numbers);
        std::cout << "Vector was doubled:\n";
        break;

    case 4:
        std::cout << "Sum of the vector: " << calculateSum(numbers) << "\n";
        break;

    case 5:
        std::cout << "Enter a number to find its multiples: ";
        std::cin >> value;
        printMultiples(numbers, value);
        break;

    case 6:
        std::cout << "Exiting program.\n";
        break;

        default:
        std::cout << "Invalid, try again.\n";
        }

    } while (choice != 6);

    return 0;
}

void printVector(const std::vector<int>& vec) {
    std::cout << "Vector contents: ";
    for (size_t i = 0; i < vec.size(); ++i) {
    std::cout << vec.at(i) << " ";
    }
    std::cout << "\n";
}

void doubleVector(std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        vec.at(i) *= 2;
    }
}

int calculateSum(const std::vector<int>& vec) {
    int sum = 0;
    for (size_t i = 0; i < vec.size(); ++i) {
    sum += vec.at(i);
    }
    return sum;
}

void printMultiples(const std::vector<int>& vec, int num) {
    std::cout << "Multiples of " << num << ": ";
    bool found = false;
    for (size_t i = 0; i < vec.size(); ++i) {
        if (vec.at(i) % num == 0) {
            std::cout << vec.at(i) << " ";
            found = true;
        }
    }
    if (!found) {
        std::cout << "Multiples weren't found.\n";
    } else {
        std::cout << "\n";
    }
}
