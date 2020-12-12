#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count else for predicate matching does not increment", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(small_cases(threshold + 1) == 0);
}

TEST_CASE("Count else for predicate not matching does increment", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(small_cases(threshold - 1) == 1);
}

TEST_CASE("Count else for predicate not matching and then matching does increment once", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    CHECK(small_cases(threshold + 1) == 0);
    REQUIRE(small_cases(threshold - 1) == 1);
}

TEST_CASE("Count else with explicit initial value for predicate matching does not increment", "[positive]") {
    auto const threshold{5};
    size_t const initial{42};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), decltype(initial)>(more_than_five, initial);
    REQUIRE(small_cases(threshold + 1) == initial);
}

TEST_CASE("Count else with explicit initial value for predicate not matching does increment", "[positive]") {
    auto const threshold{5};
    size_t const initial{42};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), decltype(initial)>(more_than_five, initial);
    REQUIRE(small_cases(threshold - 1) == initial + 1);
}
