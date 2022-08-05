add_executable(tests tests.cpp kdtrace_t.cpp)
target_link_libraries(
  tests PUBLIC
  kdtrace
  GTest::gtest
  GTest::gtest_main
  GTest::gmock
  GTest::gmock_main
)

# Allow user to run tests with `make test` or `ctest`
include(GoogleTest)
gtest_discover_tests(tests)
add_test(NAME tests COMMAND tests)

