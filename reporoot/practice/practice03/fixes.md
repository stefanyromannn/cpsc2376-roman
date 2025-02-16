# Bugs and Fixes

## Bug 1: Off-by-one error in `sumRange`
- **Issue:** The loop in `sumRange` was using `i < end`, which caused it to exclude the `end` value from the sum.
- **Fix:** Changed the loop condition from `i < end` to `i <= end`.

## Bug 2: Incorrect loop condition and logic in `containsNegative`
- **Issue:** The loop condition in `containsNegative` was using `i <= numbers.size()`, which caused an out-of-bounds access at the end of the loop. Additionally, it incorrectly checked for positive numbers instead of negative numbers.
- **Fix:** Changed the loop condition to `i < numbers.size()`, and changed the logic to `numbers[i] < 0`.

## Bug 3: Incorrect handling of empty list and off-by-one error in `findMax`
- **Issue:** The function `findMax` returned `0` for an empty list, which could be incorrect. It also had an off-by-one error in the loop, checking `i <= numbers.size()`, which caused an out-of-bounds access.
- **Fix:** Changed the empty list return value to `INT_MIN` and fixed the loop condition to `i < numbers.size()`.
