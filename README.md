# ProjectEuler
Repository containing "Project Euler" challenges from [https://projecteuler.net/archives](https://projecteuler.net/archives).

# Dependencies
 - bazel (Tested on version 0.20.0)

# How to compile
`bazel build :projectEuler`

# How to run
To run a specific challenge, give the numbers of the challenges that want to be executed as an argument.

If no arguments are given, all of the available challenges are run.

Example: `bazel run -- :projectEuler 1 2 3`

# How to add a challenge
1. Implement a class under `src/challenges` with the corresponding name.
2. Make this class inherit from `ChallengeInterface`
3. Add it to `ChallengeFactory::createChallenge()` method with the corresponfing ID
4. Make sure the new challenge class is included in `src/all_challenges.hpp`
