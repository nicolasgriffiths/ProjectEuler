#pragma once

#include "challenge_interface.hpp"

/*
 * By considering the terms in the Fibonacci sequence whose values do not exceed
 * four million, find the sum of the even-valued terms.
 */

namespace euler {
class Challenge2 : public BaseChallenge<2> {
 public:
  bool run() const override;

 private:
  static int getSum(const int threshold);
};

int Challenge2::getSum(const int threshold) {
  auto prev = 1, i = 1;
  auto sum = 0;
  while (true) {
    if (i >= threshold) break;
    if (i % 2 == 0) sum += i;
    // Get next number in the series
    auto temp = i;
    i += prev;
    prev = temp;
  }
  return sum;
}

bool Challenge2::run() const { return getSum(4e6) == 4613732; }

}  // namespace euler
