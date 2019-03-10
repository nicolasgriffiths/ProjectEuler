#pragma once

#include <vector>

namespace euler {

// Convert c-string to integer and check for invalid arguments
int convertToInt(char* s) {
  auto s2 = s;
  while (*s2) {
    if (isdigit(*s2++) == 0) {
      std::cout << "Unrecognized option: " << s
                << "\nUsage: projectEuler 1 2 3 ..." << std::endl;
      exit(1);
    }
  }
  return strtol(s, nullptr, 10);
}

// Parse arguments and return a vector containing the challenges to be executed
std::vector<int> parseArgs(int argc, char* argv[]) {
  std::vector<int> challenges;
  for (auto i = 1; i < argc; i++) challenges.push_back(convertToInt(argv[i]));
  return challenges;
}

}  // namespace euler