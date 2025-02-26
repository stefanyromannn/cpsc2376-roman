### Identified Bugs and Fixes

1. **Bug in `sumRange(int start, int end)`**:
   - **Issue:** The loop condition `i < end` causes the function to miss the value `end`.
   - **Cause:** Off-by-one error in the loop condition.
   - **Fix:** Change the loop condition from `i < end` to `i <= end` to include the end value.

2. **Bug in `containsNegative(const std::vector<int>& numbers)`**:
   - **Issue 1:** The loop condition `i <= numbers.size()` causes an out-of-bounds access on the last iteration.
   - **Issue 2:** The `if (numbers[i] > 0)` condition incorrectly checks for positive numbers instead of negative numbers.
   - **Cause:** Incorrect loop condition and incorrect comparison for detecting negative numbers.
   - **Fixes:**
     1. Change the loop condition to `i < numbers.size()` to avoid out-of-bounds access.
     2. Change the condition to `numbers[i] < 0` to correctly detect negative numbers.

3. **Bug in `findMax(const std::vector<int>& numbers)`**:
   - **Issue 1:** The function returns `0` when the list is empty, but this is not appropriate.
   - **Issue 2:** The loop condition `i <= numbers.size()` causes an out-of-bounds access on the last iteration.
   - **Issue 3:** The comparison `numbers[i] >= maxVal` causes the function to set `maxVal` to a non-unique value.
   - **Cause:** Incorrect handling of edge cases (empty list, out-of-bounds access), and incorrect comparison logic.
   - **Fixes:**
     1. Handle the empty list case by returning `std::numeric_limits<int>::min()` or throwing an exception.
     2. Change the loop condition to `i < numbers.size()`.
     3. Change the condition to `if (numbers[i] > maxVal)` to ensure only the largest value is chosen.
