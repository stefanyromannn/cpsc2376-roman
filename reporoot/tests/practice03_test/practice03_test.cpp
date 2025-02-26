#include <gtest/gtest.h>
#include <vector>
#include <climits>  // For INT_MIN

// Include the MathUtils class from the fixed practice03.cpp
#include "practice03.cpp"

TEST(MathUtilsTests, SumRangeTest) {
  // Test with standard range
  EXPECT_EQ(MathUtils::sumRange(1, 5), 15); // 1 + 2 + 3 + 4 + 5 = 15
  // Test when start == end
  EXPECT_EQ(MathUtils::sumRange(5, 5), 5); // Only 5
  // Test with negative numbers
  EXPECT_EQ(MathUtils::sumRange(-5, -1), -15); // -5 + -4 + -3 + -2 + -1 = -15
}

TEST(MathUtilsTests, ContainsNegativeTest) {
  std::vector<int> values = {3, 5, 7};
  EXPECT_FALSE(MathUtils::containsNegative(values)); // No negative numbers
  values = {3, -1, 5, 7};
  EXPECT_TRUE(MathUtils::containsNegative(values)); // Contains negative
  values = {};
  EXPECT_FALSE(MathUtils::containsNegative(values)); // Empty vector
}

TEST(MathUtilsTests, FindMaxTest) {
  std::vector<int> values = {3, -1, 5, 7};
  EXPECT_EQ(MathUtils::findMax(values), 7); // Max is 7
  values = {-5, -3, -1, -7};
  EXPECT_EQ(MathUtils::findMax(values), -1); // Max is -1
  values = {};
  EXPECT_EQ(MathUtils::findMax(values), INT_MIN); // Empty vector should return INT_MIN
  values = {3, 3, 3};
  EXPECT_EQ(MathUtils::findMax(values), 3); // All values are the same
}