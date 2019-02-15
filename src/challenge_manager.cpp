#include "challenge_manager.hpp"

#include <iostream>

namespace euler {

ChallengeManager::ChallengeManager(const std::vector<int>& challenges)
    : challenges_(challenges), skippedChallenges_{} {
  if (challenges.empty())
    std::cout << "No user-specified challenges... Execute all challenges!"
              << std::endl;
  else
    printStartSummary();
}

void ChallengeManager::runChallenges() {
  for (auto&& challengeNumber : challenges_) runChallenge(challengeNumber);
  std::cout << "Finished running challenges!" << std::endl;
  printSkippedChallenges();
}

void ChallengeManager::runChallenge(int challengeNumber) {
  // TODO create ChallengeFactory and Challenge classes. CHallenge should be an
  // interface for each concrete challenge, which must override run()
  // auto challenge = challengeFactory.create(challengeNumber); if (challenge ==
  // nullptr) {
  //   std::cout << "Challenge " << challengeNumber << "is not available"
  //             << std::endl;
  // skippedChallenges_.push_back(challengeNumber);
  // } else {
  //   challenge->run();
  // }
}

void ChallengeManager::printStartSummary() {
  std::cout << "Challenges to be executed: ";
  for (auto&& challengeNumber : challenges_)
    std::cout << " " << challengeNumber;
  std::cout << "\n";
}

void ChallengeManager::printSkippedChallenges() {
  if (skippedChallenges_.empty()) return;
  std::cout << "Skipped challenges: ";
  for (auto&& challengeNumber : skippedChallenges_)
    std::cout << " " << challengeNumber;
  std::cout << "\n";
}

}  // namespace euler