# Bugs and Fixes in `practice03.cpp`

## Bug 1: `sumRange` - Off-by-one error
- **Issue**: The `sumRange` function did not include the `end` value in the summation due to the loop condition `i < end`.
- **Fix**: Changed the loop condition to `i <= end` to include `end` in the sum.

## Bug 2: `containsNegative` - Incorrect condition and out-of-bounds access
- **Issue**: The loop condition `i <= numbers.size()` caused out-of-bounds access. The condition `numbers[i] > 0` was incorrectly checking for positive numbers instead of negative ones.
- **Fix**: Fixed the loop to iterate within valid bounds (`i < numbers.size()`) and corrected the check to `numbers[i] < 0`.

## Bug 3: `findMax` - Incorrect loop condition and out-of-bounds access
- **Issue**: The loop condition `i <= numbers.size()` caused out-of-bounds access. The comparison `numbers[i] >= maxVal` was incorrect.
- **Fix**: Changed the loop condition to `i < numbers.size()` and updated the logic to strictly check for `numbers[i] > maxVal`. Also, handled the empty list by returning `INT_MIN`.
