// Challenge factory repsonsible for creating each of the specified challenges

#include "challenge_factory.hpp"
#include "challenges/all_challenges.hpp"

namespace euler {

std::shared_ptr<ChallengeInterface> ChallengeFactory::createChallenge(
    const int challengeId) {
  switch (challengeId) {
    case 1:
      return std::make_shared<Challenge1>();
    case 2:
      return std::make_shared<Challenge2>();
    default:
      return nullptr;
  }
}

std::vector<int> ChallengeFactory::getAllChallengeIds() const {
  return allChallengeIds;
}

}  // namespace euler
