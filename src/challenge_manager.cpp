#include "challenge_manager.hpp"

#include <iostream>

namespace euler {

ChallengeManager::ChallengeManager(const std::vector<int>& challenges) {
  if (challenges.size() == 0) {
    // User didnt specify the challenges, execute them all
    std::cout << "No user-specified challenges... Execute all challenges!"
              << std::endl;
  } else {
    std::cout << "Will execute challenges: ";
    for (auto challengeNumber : challenges) std::cout << " " << challengeNumber;
    std::cout << std::endl;
  }
}

}  // namespace euler