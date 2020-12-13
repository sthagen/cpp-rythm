#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count zero for non-zero does not increment", "[positive]") {
    auto zeroes = count_zero<size_t, unsigned short>();
    REQUIRE(zeroes(42) == 0);
}

TEST_CASE("Count zero for zero does increment", "[positive]") {
    auto zeroes = count_zero<size_t, unsigned short>();
    REQUIRE(zeroes(0) == 1);
}

TEST_CASE("Count zero for zero and then non-zero does increment once", "[positive]") {
    auto zeroes = count_zero<size_t, unsigned short>();
    CHECK(zeroes(0) == 0);
    REQUIRE(zeroes(42) == 1);
}
