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
    CHECK(zeroes(0) == 1);
    REQUIRE(zeroes(42) == 1);
}

TEST_CASE("Count zero with explicit initial value for zero does increment", "[positive]") {
    size_t const initial{42};
    auto zeroes = count_zero<decltype(initial), unsigned short>(initial);
    REQUIRE(zeroes(0) == initial + 1);
}

TEST_CASE("Count zero with explicit initial value for non-zero does not increment", "[positive]") {
    size_t const initial{42};
    auto zeroes = count_zero<decltype(initial), unsigned short>(initial);
    REQUIRE(zeroes(42) == initial);
}
