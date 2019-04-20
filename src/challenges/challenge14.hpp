#pragma once

#include "challenge_interface.hpp"

/*
 * The following iterative sequence is defined for the set of positive integers:
 * n → n/2 (n is even)
 * n → 3n + 1 (n is odd)
 * Using the rule above and starting with 13, we generate the following
 * sequence: 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1 It can be seen that this
 * sequence (starting at 13 and finishing at 1) contains 10 terms. Although it
 * has not been proved yet (Collatz Problem), it is thought that all starting
 * numbers finish at 1. Which starting number, under one million, produces the
 * longest chain? NOTE: Once the chain starts the terms are allowed to go above
 * one million.
 */

namespace euler {
class Challenge14 : public BaseChallenge<14> {
 public:
  bool run() const override;

 private:
  static long stepChain(const long n);
  static long getChainLength(long n);
  static long findNumberBelowN(const long threshold);
};
long Challenge14::stepChain(const long n) {
  if (n % 2 == 0) return n / 2;
  return 3 * n + 1;
}

long Challenge14::getChainLength(long n) {
  auto ctr = 0;
  while (n > 1) {
    n = stepChain(n);
    ctr++;
  }
  return ctr;
}

long Challenge14::findNumberBelowN(const long threshold) {
  long maxLength = 0, solution = 0;
  for (long i = 1; i < threshold; i++) {
    auto tmp = getChainLength(i);
    if (tmp > maxLength) {
      maxLength = tmp;
      solution = i;
    }
  }
  return solution;
}

bool Challenge14::run() const { return findNumberBelowN(1000000) == 837799; }

}  // namespace euler
