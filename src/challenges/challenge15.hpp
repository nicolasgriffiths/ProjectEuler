#pragma once

#include <map>

#include "challenge_interface.hpp"

/*
 * Starting in the top left corner of a 2×2 grid, and only being able to move to
 * the right and down, there are exactly 6 routes to the bottom right corner.
 * How many such routes are there through a 20×20 grid?
 */

namespace euler {
class Challenge15 : public BaseChallenge<15> {
 public:
  bool run() const override;

 private:
  long findRoutesFrom(const int i, const int j, const int size,
                      std::map<std::pair<int, int>, long>& cache) const;
  long findRoutesGrid(const int size) const;
};
long Challenge15::findRoutesFrom(
    const int i, const int j, const int size,
    std::map<std::pair<int, int>, long>& cache) const {
  long nRoutes;
  auto it = cache.find(std::pair<int, int>(i, j));

  // See if we already checked this point and we can return the solution
  if (it != cache.end()) return it->second;

  // New point
  if (i == size && j == size)  // Final point
    nRoutes = 1;
  else if (i < size && j < size)  // In the grid
    nRoutes = findRoutesFrom(i + 1, j, size, cache) +
              findRoutesFrom(i, j + 1, size, cache);
  else if (i == size)  // Along "i" edge
    nRoutes = findRoutesFrom(i, j + 1, size, cache);
  else if (j == size)  // Along "j" edge
    nRoutes = findRoutesFrom(i + 1, j, size, cache);
  cache.insert(
      std::pair<std::pair<int, int>, long>(std::pair<int, int>(i, j), nRoutes));

  return nRoutes;
}

long Challenge15::findRoutesGrid(const int size) const {
  std::map<std::pair<int, int>, long> cache;
  return findRoutesFrom(0, 0, size, cache);
}

bool Challenge15::run() const { return findRoutesGrid(20) == 137846528820; }

}  // namespace euler
