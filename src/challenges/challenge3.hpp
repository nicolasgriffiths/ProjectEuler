#pragma once

#include <math.h>
#include "challenge_interface.hpp"

/*
 * What is the largest prime factor of the number 600851475143 ?
 */

namespace euler {
class Challenge3 : public BaseChallenge<3> {
 public:
  bool run() const override;

 private:
  static int findLargestPrime(const long num);
  static int findSmallestPrime(const long num);
};

int Challenge3::findLargestPrime(const long num) {
  long number = num;
  while (true) {
    long smallPrime = findSmallestPrime(number);
    if (smallPrime >= number) return smallPrime;  // Found largest prime
    number = number / smallPrime;                 // result must be integer
  }
}

int Challenge3::findSmallestPrime(const long num) {
  if (num % 2 == 0) return 2;
  for (long i = 3; i * i <= num; i += 2)
    if (num % i == 0) return i;
  return num;
}

bool Challenge3::run() const { return findLargestPrime(600851475143) == 6857; }

}  // namespace euler
