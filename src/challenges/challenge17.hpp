#pragma once

#include <string>

#include "challenge_interface.hpp"

/*
 * If the numbers 1 to 5 are written out in words: one, two, three, four,
 * five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out
 * in words, how many letters would be used?
 *
 * NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
 * forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20
 * letters. The use of "and" when writing out numbers is in compliance with
 * British usage.
 */

namespace euler {
class Challenge17 : public BaseChallenge<17> {
 public:
  bool run() const override;

 private:
  static bool isSpecialLength(const std::string& num, const int pos);
  static int getSpecialLength(const int digit, const int pos);
  static int getStandardLength(const int digit, const int pos);
  static bool updateLetterCount(const std::string& num, const int pos,
                                int& result);
  static int countLetters(const std::string& num);
  static int getLettersUpTo(const int threshold);

  static std::vector<int> unitsLength;
  static std::vector<int> decadesLength;
  static std::vector<int> hundredsLength;
  static std::vector<int> teensLength;
};

std::vector<int> Challenge17::unitsLength = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};
std::vector<int> Challenge17::decadesLength = {0, 3, 6, 6, 5, 5, 5, 7, 6, 6};
std::vector<int> Challenge17::hundredsLength = {0,  13, 13, 15, 14,
                                                14, 13, 15, 15, 14};
std::vector<int> Challenge17::teensLength = {0, 6, 6, 8, 8, 7, 7, 9, 8, 8};

bool Challenge17::isSpecialLength(const std::string& num, const int pos) {
  auto subNum = (std::stoi(num) % 100);
  if (pos == 1 && subNum < 20 && subNum > 10) return true;  // Teens
  if (pos == 3 && subNum == 0 &&
      std::stoi(num.substr(num.size() - pos, 1)) != 0)  // Exact hundreds
    return true;
  return false;  // Normal number
}

int Challenge17::getSpecialLength(const int digit, const int pos) {
  int length;
  if (pos == 1) length = teensLength[digit];         // Teens
  if (pos == 3) length = hundredsLength[digit] - 3;  // Remove 'and'
  return length;
}

int Challenge17::getStandardLength(const int digit, const int pos) {
  int length;
  if (pos == 1)
    length = unitsLength[digit];
  else if (pos == 2)
    length = decadesLength[digit];
  else if (pos == 3)
    length = hundredsLength[digit];
  else
    length = 11;  // one thousand
  return length;
}

bool Challenge17::updateLetterCount(const std::string& num, const int pos,
                                    int& result) {
  if ((pos == (num.size() - 1) || (pos == (num.size() - 3))) &&
      isSpecialLength(num, num.size() - pos)) {
    result += getSpecialLength(std::stoi(num.substr(pos, 1)), num.size() - pos);
    return true;
  }
  result += getStandardLength(std::stoi(num.substr(pos, 1)), num.size() - pos);
  return false;
}

int Challenge17::countLetters(const std::string& num) {
  int result = 0;
  for (int pos = num.size() - 1; pos >= 0; pos--) {
    bool skipNext =
        updateLetterCount(num, pos, result);  // letters for each digit
    if (skipNext) pos--;
  }
  return result;
}

int Challenge17::getLettersUpTo(const int threshold) {
  int result = 0;
  for (int num = 1; num <= threshold; num++)
    result += countLetters(std::to_string(num));  // letters for each number
  return result;
}

bool Challenge17::run() const { return getLettersUpTo(1000) == 21124; }

}  // namespace euler
