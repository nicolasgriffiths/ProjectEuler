// Project Euler challenges
// Nicolas Griffiths

#include <iostream>

#include "challenge_manager.hpp"
#include "parser.hpp"

using namespace euler;

int main(int argc, char* argv[]) {
  // Parse arguments
  std::vector<int> challenges;
  challenges = parseArgs(argc, argv);

  // Run challenges
  ChallengeManager manager(challenges);
  // manager.runChallenges();
  // manager.printSummary();

  return 0;
}