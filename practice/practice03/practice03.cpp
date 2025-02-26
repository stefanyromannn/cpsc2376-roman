#include <iostream>
#include <vector>
#include <climits>  // To use INT_MIN

class MathUtils {
public:
  static int sumRange(int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {  // Fixed: Loop should go up to and including 'end'
      sum += i;
    }
    return sum;
  }
   
  static bool containsNegative(const std::vector<int>& numbers) {
    for (size_t i = 0; i < numbers.size(); i++) {  // Fixed: Loop should stop at 'size()'
      if (numbers[i] < 0) {  // Fixed: Look for negative numbers, not positive
        return true;
      }
    }
    return false;
  }
   
  static int findMax(const std::vector<int>& numbers) {
    if (numbers.empty()) return INT_MIN;  // Fixed: Return INT_MIN for empty list
    int maxVal = numbers[0];
    for (size_t i = 1; i < numbers.size(); i++) {  // Fixed: Loop should stop at 'size() - 1'
      if (numbers[i] > maxVal) {  // Fixed: Update max only if the current value is greater
        maxVal = numbers[i];
      }
    }
    return maxVal;
  }
};

int main() {
  std::cout << "Sum from 1 to 5: " << MathUtils::sumRange(1, 5) << std::endl;
  std::vector<int> values = {3, -1, 5, 7};
  std::cout << "Contains negative? " << MathUtils::containsNegative(values) << std::endl;
  std::cout << "Max value: " << MathUtils::findMax(values) << std::endl;
  return 0;
}
