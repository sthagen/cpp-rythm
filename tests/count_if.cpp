#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count if for predicate matching does increment", "[positive]") {
    auto more_than_five = [](auto x){ return x > 5;};
    auto larger_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    REQUIRE(larger_cases(42) == 1);
}
