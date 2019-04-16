#pragma once

#include <string>

#include "challenge_interface.hpp"

/*
 * A Pythagorean triplet is a set of three natural numbers, a < b < c, for
 * which, a2 + b2 = c2 For example, 32 + 42 = 9 + 16 = 25 = 52.
 * There exists exactly one Pythagorean triplet for which a + b + c = 1000.
 * Find the product abc.
 */

namespace euler {
class Challenge9 : public BaseChallenge<9> {
 public:
  bool run() const override;

 private:
  static long findPythagoreanTripleProduct(const int sum);
  static bool isPythagoreanTriplet(const int a, const int b, const int c);
};

bool Challenge9::isPythagoreanTriplet(const int a, const int b, const int c) {
  return a * a + b * b == c * c;
}

long Challenge9::findPythagoreanTripleProduct(const int sum) {
  for (auto a = 1; a < sum / 2; a++)
    for (auto b = a; b < (sum - a - 1); b++) {
      auto c = sum - a - b;
      if (isPythagoreanTriplet(a, b, c)) return a * b * c;
    }
  return 0;
}

bool Challenge9::run() const {
  return findPythagoreanTripleProduct(1000) == 31875000;
}

}  // namespace euler
