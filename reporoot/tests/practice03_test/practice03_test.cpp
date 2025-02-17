// practice03_test.cpp
#include <gtest/gtest.h>
#include <vector>
#include "practice03.cpp"  // Include the implementation directly

TEST(MathUtilsTest, SumRange) {
    EXPECT_EQ(MathUtils::sumRange(1, 5), 15);  // 1 + 2 + 3 + 4 + 5 = 15
    EXPECT_EQ(MathUtils::sumRange(5, 5), 5);   // Only one number (5)
    EXPECT_EQ(MathUtils::sumRange(-3, 1), -3); // -3 + -2 + -1 + 0 + 1 = -3
}

TEST(MathUtilsTest, ContainsNegative) {
    std::vector<int> values1 = {1, 2, -1, 4}; 
    std::vector<int> values2 = {1, 2, 3, 4};
    std::vector<int> values3 = {};
    EXPECT_TRUE(MathUtils::containsNegative(values1));  // Contains negative (-1)
    EXPECT_FALSE(MathUtils::containsNegative(values2)); // No negative numbers
    EXPECT_FALSE(MathUtils::containsNegative(values3)); // Empty vector
}

TEST(MathUtilsTest, FindMax) {
    std::vector<int> values1 = {3, 5, 7, 2}; 
    std::vector<int> values2 = {1};
    std::vector<int> values3 = {};
    EXPECT_EQ(MathUtils::findMax(values1), 7);   // 7 is the maximum
    EXPECT_EQ(MathUtils::findMax(values2), 1);   // Only one element
    EXPECT_EQ(MathUtils::findMax(values3), INT_MIN); // Should return INT_MIN for empty
}
