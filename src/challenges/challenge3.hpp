#pragma once

#include <math.h>
#include "challenge_interface.hpp"

/*
 * What is the largest prime factor of the number 600851475143 ?
 */

namespace euler {
class Challenge3 : public ChallengeInterface {
 public:
  bool run() const override;
  int getId() const override;
private:
  static int findLargestPrime(const long num);
  static int findSmallestPrime(const long num);
};

int Challenge3::findLargestPrime(const long num) {
  long number = num;
  while (true) {
    long smallPrime = findSmallestPrime(number);
    if (smallPrime < number)
      number = number / smallPrime;  // result must be integer
    else
      return smallPrime;  // Found largest prime
  }
}

int Challenge3::findSmallestPrime(const long num) {
  for (long i = 2; i < sqrt(num); i++)
    if ((num % i) == 0) return i;  // Found divisor that is prime
  return num;                      // The number is prime
}

bool Challenge3::run() const { return findLargestPrime(600851475143) == 6857; }

int Challenge3::getId() const { return 3; }

}  // namespace euler
