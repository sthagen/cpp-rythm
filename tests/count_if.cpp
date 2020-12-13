#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count if for predicate matching does increment", "[positive]") {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto larger_cases = count_if<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(larger_cases(threshold + 1) == 1);
}
