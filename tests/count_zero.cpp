#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count zero for non-zero does not increment", "[positive]") {
    auto zeroes = count_zero<size_t, unsigned short>();
    REQUIRE(zeroes(42) == 0);
}

TEST_CASE("Count zero for zero does increment", "[positive]") {
    auto zeroes = count_zero<size_t>();
    REQUIRE(zeroes(0) == 1);
}
