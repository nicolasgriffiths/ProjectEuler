// Project Euler challenges
// Nicolas Griffiths

#include <iostream>

#include "challenge_manager.hpp"
#include "parser.hpp"

using namespace euler;

int main(int argc, char* argv[]) {
  // Parse arguments
  auto challenges = parseArgs(argc, argv);

  // Create manager
  ChallengeManager manager(challenges);

  // Run challenges and return 0 if successful
  return static_cast<int>(manager.runChallenges() != true);
}