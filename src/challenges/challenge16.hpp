#pragma once

#include <string>

#include "challenge_interface.hpp"

/*
 * 215 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 * What is the sum of the digits of the number 21000?
 */

namespace euler {
class Challenge16 : public BaseChallenge<16> {
 public:
  bool run() const override;

 private:
  static int getSumDigits(const std::string& num);
  static std::string multiplyByTwo(const std::string& num);
  static int getSumDigitsPowerTwo(const int exponent);
};

int Challenge16::getSumDigits(const std::string& num) {
  int result = 0;
  for (const auto& c : num) result += c - '0';
  return result;
}

std::string Challenge16::multiplyByTwo(const std::string& num) {
  std::string result;
  int carry = 0;
  for (int i = num.size() - 1; i >= 0; i--) {
    int digit = carry + 2 * (num[i] - '0');
    result.insert(0, std::to_string(digit % 10));
    carry = std::floor(digit / 10);
  }
  if (carry != 0) result.insert(0, std::to_string(carry));
  return result;
}

int Challenge16::getSumDigitsPowerTwo(const int exponent) {
  std::string result = "1";
  for (auto i = 0; i < exponent; i++) result = multiplyByTwo(result);
  return getSumDigits(result);
}

bool Challenge16::run() const { return getSumDigitsPowerTwo(1000) == 1366; }

}  // namespace euler
