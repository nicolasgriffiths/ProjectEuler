#include "challenge_manager.hpp"

#include <iostream>

namespace euler {

ChallengeManager::ChallengeManager(const std::vector<int>& challengeIds)
    : skippedChallenges_{} {
  if (challengeIds.empty()) {
    std::cout << "No user-specified challenges... Execute all challenges!"
              << std::endl;
    for (auto&& challengeId : challengeFactory_.getAllChallengeIds())
      challenges_.push_back(challengeFactory_.createChallenge(challengeId));
  } else {
    for (auto&& challengeId : challengeIds) {
      auto challenge = challengeFactory_.createChallenge(challengeId);
      if (challenge != nullptr)
        challenges_.push_back(challengeFactory_.createChallenge(challengeId));
      else
        skippedChallenges_.push_back(challengeId);
    }
  }
}

bool ChallengeManager::runChallenges() {
  bool globalSuccess = true;
  printStartSummary();
  for (auto&& challenge : challenges_) {
    std::cout << "Challenge " << challenge->getId() << " --> ";
    auto result = challenge->run() ? "SUCCESS" : "FAIL";
    globalSuccess = globalSuccess && result;
    std::cout << result << std::endl;
  }
  std::cout << std::endl;
  printEndSummary();
  return globalSuccess;
}

void ChallengeManager::printStartSummary() {
  std::cout << "Challenges to be executed: ";
  for (auto&& challenge : challenges_) std::cout << challenge->getId() << " ";
  std::cout << std::endl << std::endl;
}

void ChallengeManager::printEndSummary() {
  if (skippedChallenges_.empty()) return;
  std::cout << "Skipped challenges: " << std::endl;
  for (auto&& challengeNumber : skippedChallenges_)
    std::cout << challengeNumber << std::endl;
  std::cout << std::endl;
}

}  // namespace euler