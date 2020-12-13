#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count if for predicate matching does increment", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto larger_cases = count_if<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(larger_cases(threshold + 1) == 1);
}

TEST_CASE("Count if for predicate not matching does not increment", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_if<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(small_cases(threshold - 1) == 0);
}

TEST_CASE("Count if for predicate not matching and then matching does increment once", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_if<decltype(more_than_five), size_t>(more_than_five);
    CHECK(small_cases(threshold - 1) == 0);
    REQUIRE(small_cases(threshold + 1) == 1);
}

TEST_CASE("Count if with explicit initial value for predicate matching does increment", "[positive]") {
    auto const threshold{5};
    size_t const initial{42};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_if<decltype(more_than_five), decltype(initial)>(more_than_five, initial);
    REQUIRE(small_cases(threshold + 1) == initial + 1);
}

TEST_CASE("Count if with explicit initial value for predicate not matching does not increment", "[positive]") {
    auto const threshold{5};
    size_t const initial{42};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_if<decltype(more_than_five), decltype(initial)>(more_than_five, initial);
    REQUIRE(small_cases(threshold - 1) == initial);
}
