#include <gtest/gtest.h>
#include "practice03.cpp"  // Make sure to include the file you're testing

// Test cases for sumRange
TEST(MathUtilsTest, SumRangeTest) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 10);  // 1 + 2 + 3 + 4 = 10
    EXPECT_EQ(MathUtils::sumRange(0, 0), 0);   // Edge case: start == end
    EXPECT_EQ(MathUtils::sumRange(-3, 3), 0);  // Negative values: -3 + -2 + -1 + 0 + 1 + 2 = 0
}

// Test cases for containsNegative
TEST(MathUtilsTest, ContainsNegativeTest) {
    std::vector<int> values1 = {3, -1, 5, 7};
    EXPECT_TRUE(MathUtils::containsNegative(values1));  // Should return true because of -1

    std::vector<int> values2 = {3, 5, 7};
    EXPECT_FALSE(MathUtils::containsNegative(values2));  // Should return false because there are no negative numbers

    std::vector<int> values3 = {};
    EXPECT_FALSE(MathUtils::containsNegative(values3));  // Empty list, should return false
}

// Test cases for findMax
TEST(MathUtilsTest, FindMaxTest) {
    std::vector<int> values1 = {3, -1, 5, 7};
    EXPECT_EQ(MathUtils::findMax(values1), 7);  // The maximum value is 7

    std::vector<int> values2 = {3, 5, 7, 5};
    EXPECT_EQ(MathUtils::findMax(values2), 7);  // The maximum value is 7

    std::vector<int> values3 = {3, 3, 3};
    EXPECT_EQ(MathUtils::findMax(values3), 3);  // All values are the same, 3
}
