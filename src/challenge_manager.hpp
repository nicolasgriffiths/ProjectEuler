#pragma once

// Challenge manager responsible for orchestrating the challenges execution

#include <vector>
#include "challenge_factory.hpp"

namespace euler {

class ChallengeManager {
 public:
  // Build challenge manager with the challenges that want to be run
  explicit ChallengeManager(const std::vector<int>& challengeIds);
  // Run all challenges specified in constructor
  void runChallenges();

 private:
  void printStartSummary();
  void printEndSummary();

  std::vector<int> skippedChallenges_;
  std::vector<std::shared_ptr<ChallengeInterface>> challenges_;
  ChallengeFactory challengeFactory_;
};

}  // namespace euler