#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count true for true does increment", "[positive]") {
    auto successes = count_true<size_t>();
    REQUIRE(successes(true) == 1);
}

TEST_CASE("Count true for false does not increment", "[positive]") {
    auto successes = count_true<size_t>();
    REQUIRE(successes(false) == 0);
}

TEST_CASE("Count true for true and then false does increment once", "[positive]") {
    auto successes = count_true<size_t>();
    CHECK(successes(true) == 1);
    REQUIRE(successes(false) == 1);
}

TEST_CASE("Count true with explicit initial value for true does increment", "[positive]") {
    size_t const initial{42};
    auto successes = count_true<decltype(initial)>(initial);
    REQUIRE(successes(true) == initial + 1);
}
