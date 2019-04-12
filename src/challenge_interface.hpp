#pragma once

// Challenge Interface which forms the base class from which all other
// challenges are derived from

namespace euler {

class ChallengeInterface {
 public:
  virtual ~ChallengeInterface() {}
  virtual bool run() const = 0;
  virtual int getId() const = 0;
};

template <int ID>
class BaseChallenge : public ChallengeInterface {
 public:
  virtual ~BaseChallenge() {}
  virtual bool run() const = 0;
  int getId() const { return ID; }
};

}  // namespace euler
