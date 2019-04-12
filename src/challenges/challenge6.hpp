#pragma once

#include "challenge_interface.hpp"

/*
 * x = sum of squares of all the natural numbers up to N
 * y = square of the sum of all the natural numbers up to N
 * find y-x for N=100
 */

namespace euler {
class Challenge6 : public BaseChallenge<6> {
 public:
  bool run() const override;

 private:
  static int getDifference(const int num);
};

int Challenge6::getDifference(const int num) {
  return (3 * (pow(num, 4) - pow(num, 2)) + 2 * (pow(num, 3) - num)) / 12;
}

bool Challenge6::run() const { return getDifference(100) == 25164150; }

}  // namespace euler
