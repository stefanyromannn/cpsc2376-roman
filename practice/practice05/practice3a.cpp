#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>  

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "Enter # of elements: ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
    std::cin >> value;
    numbers.push_back(value);
    }

    std::cout << "Squared values: ";
    std::for_each(numbers.begin(), numbers.end(), [](int num) {
    std::cout << (num * num) << " ";
    });
    std::cout << std::endl;

    int sumOfSquares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int total, int num) {
    return total + (num * num);
    });

    std::cout << "Sum of squared values: " << sumOfSquares << std::endl;

    return 0;
}