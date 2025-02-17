# Bugs and Fixes in `practice03.cpp`

## 1. Bug in `sumRange`
   - **Bug**: The loop in `sumRange` uses the condition `i < end`, which causes it to exclude the `end` value.
   - **Fix**: Change the loop condition to `i <= end` to include the `end` value in the sum.

## 2. Bug in `containsNegative`
   - **Bug 1**: The loop condition `i <= numbers.size()` causes out-of-bounds access.
   - **Fix 1**: Change the loop condition to `i < numbers.size()`.
   - **Bug 2**: The logic for detecting negative numbers is reversed.
   - **Fix 2**: Change `if (numbers[i] > 0)` to `if (numbers[i] < 0)` to correctly detect negative numbers.

## 3. Bug in `findMax`
   - **Bug 1**: The loop condition `i <= numbers.size()` causes out-of-bounds access.
   - **Fix 1**: Change the loop condition to `i < numbers.size()`.
   - **Bug 2**: The return value for an empty vector should not be `0`.
   - **Fix 2**: Return `INT_MIN` for an empty vector instead of `0`.

## Additional Information
These bugs were causing incorrect behavior in the program, especially with edge cases such as empty lists and off-by-one errors.
