#pragma once

// Challenge factory repsonsible for creating each of the specified challenges

#include <memory>
#include <vector>
#include "challenge_interface.hpp"

namespace euler {

class ChallengeFactory {
 public:
  std::shared_ptr<ChallengeInterface> createChallenge(const int challengeId);
  std::vector<int> getAllChallengeIds() const;
};

}  // namespace euler
