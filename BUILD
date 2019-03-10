# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "projectEuler",
    srcs = glob([
        "src/**/*.hpp",
        "src/**/*.cpp"
        ]),
    includes = ["src"],
    copts = ["-W", "-Wall", "-Wextra", "-Wpedantic", "-std=c++11"]
)

cc_test(
    name = "tests",
    srcs = glob(["test/*.cpp"]),
    deps = ["@gtest//:gtest_main"]
)