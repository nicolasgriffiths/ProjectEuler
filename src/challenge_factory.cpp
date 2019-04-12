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
    case 3:
      return std::make_shared<Challenge3>();
    case 4:
      return std::make_shared<Challenge4>();
    case 5:
      return std::make_shared<Challenge5>();
    case 6:
      return std::make_shared<Challenge6>();
    default:
      return nullptr;
  }
}

std::vector<int> ChallengeFactory::getAllChallengeIds() const {
  return allChallengeIds;
}

}  // namespace euler
