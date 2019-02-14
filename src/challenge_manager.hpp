#pragma once

// Challenge manager responsible for orchestrating the challenges execution

#include <vector>

namespace euler {

class ChallengeManager {
 public:
  explicit ChallengeManager(const std::vector<int>& challenges);
};

}  // namespace euler