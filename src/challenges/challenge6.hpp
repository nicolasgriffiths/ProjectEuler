#pragma once

#include "challenge_interface.hpp"

/*
 * The sum of the squares of the first ten natural numbers is,
 * 12 + 22 + ... + 102 = 385 The square of the sum of the first ten natural
 * numbers is, (1 + 2 + ... + 10)2 = 552 = 3025 Hence the difference between the
 * sum of the squares of the first ten natural numbers and the square of the sum
 * is 3025 − 385 = 2640. Find the difference between the sum of the squares of
 * the first one hundred natural numbers and the square of the sum.
 */

namespace euler {
class Challenge6 : public BaseChallenge<6> {
 public:
  bool run() const override;

 private:
  static int getDifference(const int num);
};

// Mathematically reduced formulas for square of sum minus sum of squares
int Challenge6::getDifference(const int num) {
  return (3 * (pow(num, 4) - pow(num, 2)) + 2 * (pow(num, 3) - num)) / 12;
}

bool Challenge6::run() const { return getDifference(100) == 25164150; }

}  // namespace euler
