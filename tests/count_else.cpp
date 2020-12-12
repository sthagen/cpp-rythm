#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count else for predicate matching does not increment", "[positive]") {
    auto more_than_five = [](auto x){ return x > 5;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(small_cases(42) == 0);
}

TEST_CASE("Count else for predicate not matching does increment", "[positive]") {
    auto const threshold = 5;
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(small_cases(threshold - 1) == 1);
}
