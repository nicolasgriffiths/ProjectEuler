#pragma once

#include <iostream>
#include "challenge_interface.hpp"

/*
 * By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
 * that the 6th prime is 13. What is the 10 001st prime number?
 */

namespace euler {
class Challenge7 : public BaseChallenge<7> {
 public:
  bool run() const override;

 private:
  static int findSmallestPrime(const long num);
  static int findPrimeNumber(const int number);
};

int Challenge7::findSmallestPrime(const long num) {
  if (num % 2 == 0) return 2;
  for (long i = 3; i * i <= num; i += 2)
    if (num % i == 0) return i;
  return num;
}

int Challenge7::findPrimeNumber(const int number) {
  if (number == 1) return 2;
  for (int counter = 2, i = 3; counter <= number; i += 2)
    if (i == findSmallestPrime(i) && number == counter++) return i;
}

bool Challenge7::run() const { return findPrimeNumber(10001) == 104743; }

}  // namespace euler
