#include <iostream>
#include <iomanip> 
#include <limits>  


template <typename T>
T calculate(T num1, T num2, char operation) {
    switch (operation) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 != 0)
                return num1 / num2;
            else {
                std::cerr << "Error: You can't use zero!" << std::endl;
                return 0;
            }
        default:
            std::cerr << "Invalid operation!" << std::endl;
            return 0;
    }
}

template <typename T>
bool isValidNumber(T& number) {
    std::cin >> number;
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false; 
    }
    return true; 
}

int main() {
    double num1, num2; 
    char operation;
    
  
    std::cout << "Enter first number: ";
    while (!isValidNumber(num1)) {
        std::cout << "Invalid input. Please enter a valid number: ";
    }

 
    std::cout << "Enter second number: ";
    while (!isValidNumber(num2)) {
        std::cout << "Invalid input. Please enter a valid number: ";
    }
    
   
    std::cout << "Great. Now pick a process, (+, -, *, /): ";
    while (true) {
        std::cin >> operation;
        if (operation == '+' || operation == '-' || operation == '*' || operation == '/') {
            break;
        } else {
            std::cout << "Invalid! Please enter one of (+, -, *, /): ";
        }
    }

    if (num1 == static_cast<int>(num1) && num2 == static_cast<int>(num2)) {
        int result = calculate(static_cast<int>(num1), static_cast<int>(num2), operation);
        std::cout << "Result: " << result << std::endl;
    } else {
  
        double result = calculate(num1, num2, operation);
        std::cout << "Result: " << std::fixed << std::setprecision(2) << result << std::endl;
    }
    
    return 0;
}