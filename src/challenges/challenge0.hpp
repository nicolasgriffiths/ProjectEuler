#pragma once

// Test class to verify that the challenge manager is working

#include <iostream>

#include "challenge_interface.hpp"

namespace euler {

class Challenge0 : public ChallengeInterface {
 public:
  bool run() const override;
  int getId() const override;
};

bool Challenge0::run() const { return true; }

int Challenge0::getId() const { return 0; }

}  // namespace euler
