#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count zero for non-zero does not set to zero", "[positive]") {
    auto zeroes = count_zero<size_t, unsigned short>();
    REQUIRE(zeroes(true) == 0);
}
