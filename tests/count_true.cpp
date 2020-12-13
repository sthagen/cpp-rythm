#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count true for true does increment", "[positive]") {
    auto successes = count_true<size_t>();
    REQUIRE(successes(true) == 1);
}

TEST_CASE("Count true for false does not increment", "[positive]") {
    auto failusuccessesres = count_false<size_t>();
    REQUIRE(successes(false) == 0);
}
