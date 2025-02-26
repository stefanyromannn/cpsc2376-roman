# Bugs and Fixes for `practice03.cpp`

## Bug 1: Off-by-one error in `sumRange`

- **Issue**: The loop condition `i < end` causes the `end` value to be excluded from the sum.
- **Fix**: The loop condition was updated to `i <= end` to include the `end` value in the sum.
  
## Bug 2: Incorrect loop in `containsNegative`

- **Issue 1**: The loop condition `i <= numbers.size()` leads to out-of-bounds access on the last iteration.
- **Issue 2**: The function incorrectly looks for positive numbers instead of negative numbers.
- **Fix**: The loop condition was updated to `i < numbers.size()`, and the condition was changed to `numbers[i] < 0` to correctly identify negative numbers.

## Bug 3: Incorrect behavior in `findMax`

- **Issue 1**: The loop condition `i <= numbers.size()` causes an out-of-bounds access.
- **Issue 2**: The check for an empty vector returns `0`, which isn’t ideal.
- **Fix**: The loop condition was updated to `i < numbers.size()`, and the function now returns `INT_MIN` for empty vectors.
