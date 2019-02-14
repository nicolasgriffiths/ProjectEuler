# ProjectEuler
Repository containing "Project Euler" challenges from [https://projecteuler.net/archives](https://projecteuler.net/archives).

# Dependencies
 - bazel (Tested on 0.20.0)

# How to compile
`bazel build :projectEuler`

# How to run
To run a specific challenge, call give the numbers of the challenges that want to be executed as an argument.

If no arguments are given, all of the challenges are run.

Example: `bazel run -- :projectEuler 1 2 3`
