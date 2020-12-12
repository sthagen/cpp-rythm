#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count false for true does not increment", "[positive]") {
    auto failures = count_false<size_t>();
    REQUIRE(failures(true) == 0);
}
