#pragma once

#include <math.h>
#include <algorithm>
#include <string>
#include "challenge_interface.hpp"

/*
 * Find the largest palindrome made from the product of two 3-digit numbers.
 * Search through multiplications of two digits starting from the maximum and
 * searhing down until finding solution. The result of the multiplication
 * decreases in a quadratic surface fashion and it can be predicted which
 * multiplication to search next. (Diagonally if plotted in 2D)
 */

namespace euler {
class Challenge4 : public BaseChallenge<4> {
 public:
  bool run() const override;

 private:
  static int findLargestPalindrome(const int maxMultiplier);
  static bool isPalindrome(const int num);
};

int Challenge4::findLargestPalindrome(const int maxMultiplier) {
  for (auto set = 0; set < (2 * maxMultiplier); ++set) {
    auto iterations = floor(set / 2) + 1;
    int x, y;
    for (x = iterations - 1, y = set - iterations + 1; x >= 0; --x, ++y) {
      auto num = (maxMultiplier - x) * (maxMultiplier - y);
      if (isPalindrome(num)) return num;
    }
  }
  return 0;
}

bool Challenge4::isPalindrome(const int num) {
  auto num_string_reversed = std::to_string(num);
  std::reverse(num_string_reversed.begin(), num_string_reversed.end());
  return std::to_string(num) == num_string_reversed;
}

bool Challenge4::run() const { return findLargestPalindrome(999) == 906609; }

}  // namespace euler
