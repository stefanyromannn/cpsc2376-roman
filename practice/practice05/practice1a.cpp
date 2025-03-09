#include <iostream>
#include <vector>
#include <iterator>

int main() {
    std::vector<int> numbers;
    int n, value;
    
    std::cout << "Enter amount of intergers you want: ";
    std::cin >> n;
    
    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    std::cout << "You entered: ";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int evenSum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenSum += *it;
        }
    }

    std::cout << "Sum of even numbers: " << evenSum << std::endl;

    return 0;
}