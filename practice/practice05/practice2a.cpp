#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "Enter the number of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
    std::cin >> value;
    numbers.push_back(value);
    }

    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    int product = std::accumulate(numbers.begin(), numbers.end(), 1, std::multiplies<int>());

    std::cout << "Sum of elements: " << sum << std::endl;
    std::cout << "Product of elements: " << product << std::endl;

    return 0;
}