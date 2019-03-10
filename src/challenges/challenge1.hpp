#pragma once

#include <algorithm>
#include "challenge_interface.hpp"

/*
 * Find the sum of all the multiples of 3 or 5 below 1000
 * This challenge has been coded thinking of scaling the problem to an arbitrary
 * number of divisors and threshold. This method optimizes by only searching
 * through the numbers it strictly needs
 */

namespace euler {
class Challenge1 : public ChallengeInterface {
 public:
  static int getSum(const std::vector<int> divisors, const int threshold);
  static std::vector<int> getCycle(const std::vector<int> divisors);
  bool run() const override;
  int getId() const override;
};

int Challenge1::getSum(const std::vector<int> divisors, const int threshold) {
  // To optimize this, only go through the multiples, which get repeated in
  // cycle. The difference between consecutive numbers is `cycle`
  std::vector<int> cycle = getCycle(divisors);
  int sum = 0, num = 0, index = 0;
  while (true) {
    num += cycle.at((index++) % cycle.size());
    if (num >= threshold) break;
    sum += num;
  }
  return sum;
}

std::vector<int> Challenge1::getCycle(const std::vector<int> divisors) {
  // Find maximum multiple
  auto maxNum = 1;
  for (auto divisor : divisors) maxNum *= divisor;

  // Build vector of differences between multiples
  auto lastMultiple = 0;
  std::vector<int> cycle;
  for (auto i = 1; i <= maxNum; ++i)
    if (std::any_of(divisors.begin(), divisors.end(),
                    [i](int d) { return i % d == 0; })) {
      cycle.push_back(i - lastMultiple);
      lastMultiple = i;
    }
  return cycle;
}

bool Challenge1::run() const { return getSum({3, 5}, 1000) == 233168; }

int Challenge1::getId() const { return 1; }

}  // namespace euler
