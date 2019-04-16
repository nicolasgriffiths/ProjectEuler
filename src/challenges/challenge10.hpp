#pragma once

#include "challenge_interface.hpp"

/*
 * The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
 * Find the sum of all the primes below two million.
 */

namespace euler {
class Challenge10 : public BaseChallenge<10> {
 public:
  bool run() const override;

 private:
  static int isPrime(const long num);
  static long findSumOfFirstPrimesBelow(const int n);
};

int Challenge10::isPrime(const long num) {
  if (num == 2 || num == 3) return true;
  if (num % 2 == 0) return false;
  for (long i = 3; i * i <= num; i += 2)
    if (num % i == 0) return false;
  return true;
}

long Challenge10::findSumOfFirstPrimesBelow(const int n) {
  if (n == 1) return 2;
  long sum = 0;
  for (int i = 2; i <= n; i++)
    if (isPrime(i)) sum += i;
  return sum;
}

bool Challenge10::run() const {
  return findSumOfFirstPrimesBelow(2000000) == 142913828922;
}

}  // namespace euler
