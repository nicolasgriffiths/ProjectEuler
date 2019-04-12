#pragma once

#include <map>

#include "challenge_interface.hpp"

/*
 * 2520 is the smallest number that can be divided by each of the numbers from
 * 1 to 10 without any remainder. What is the smallest positive number that is
 * evenly divisible by all of the numbers from 1 to 20?
 */

namespace euler {
class Challenge5 : public BaseChallenge<5> {
 public:
  bool run() const override;

 private:
  // Finds the smallest prime factor of num
  static int findSmallestPrime(const int num);
  // Get a map containing all prime factors and how many times each
  static std::map<int, int> getFactors(const int num);
  // Update the global factors if update factors has new or more times
  static void updateFactors(std::map<int, int>& globalFactors,
                            const std::map<int, int>& updateFactors);
  // Multiply all factors to get the MCM
  static int getSmallestCommonMultiple(const std::map<int, int>& factors);
  // Smallest number that is evenly divisible by all natural numbers up to num
  static int getSmallestNumberDivisibleUpTo(const int num);
};

int Challenge5::findSmallestPrime(const int num) {
  if (num % 2 == 0) return 2;
  for (int i = 3; i * i <= num; i += 2)
    if (num % i == 0) return i;
  return num;
}

std::map<int, int> Challenge5::getFactors(int num) {
  std::map<int, int> factors{};
  int factor = 1;
  while (factor != num) {
    num /= factor;
    factor = findSmallestPrime(num);
    auto it = factors.find(factor);
    if (it == factors.end())  // New element
      factors.insert(std::pair<int, int>(factor, 1));
    else  // Update to a larger value
      it->second++;
  }
  return factors;
}

void Challenge5::updateFactors(std::map<int, int>& globalFactors,
                               const std::map<int, int>& updateFactors) {
  for (const auto& [key, value] : updateFactors) {
    auto it = globalFactors.find(key);
    if (it == globalFactors.end())  // New element
      globalFactors.insert(std::pair<int, int>(key, value));
    else  // Update to a larger value if needed
      it->second = std::max(value, it->second);
  }
}

int Challenge5::getSmallestCommonMultiple(const std::map<int, int>& factors) {
  auto num = 1;
  for (const auto& [key, value] : factors) num *= pow(key, value);
  return num;
}

int Challenge5::getSmallestNumberDivisibleUpTo(const int num) {
  std::map<int, int> factors{};
  for (int i = num; i > 1; --i) updateFactors(factors, getFactors(i));
  return getSmallestCommonMultiple(factors);
}

bool Challenge5::run() const {
  return getSmallestNumberDivisibleUpTo(20) == 232792560;
}

}  // namespace euler
