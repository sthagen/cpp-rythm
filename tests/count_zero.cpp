#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count zero for non-zero does not increment", "[positive]") {
    auto zeroes = count_zero();
    REQUIRE(zeroes(true) == 0);
}
