#pragma once

// Challenge manager responsible for orchestrating the challenges execution

#include <vector>

namespace euler {

class ChallengeManager {
 public:
  // Build challenge manager with the challenges that want to be run
  explicit ChallengeManager(const std::vector<int>& challenges);
  // Run all challenges specified in constructor
  void runChallenges();

 private:
  void runChallenge(int testNumber);
  void printStartSummary();
  void printSkippedChallenges();

  std::vector<int> challenges_;
  std::vector<int> skippedChallenges_;
  // ChallengeFactory challengeFactory_;
};

}  // namespace euler