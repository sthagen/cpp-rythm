#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count true for true increments", "[positive]") {
    auto successes = count_true<size_t>();
    REQUIRE(successes(true) == 1);
}
