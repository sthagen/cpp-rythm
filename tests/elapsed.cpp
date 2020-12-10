#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Elapsed unsigned integral called with start value returns zero", "[positive]") {
    auto events = elapsed<size_t>(0);
    REQUIRE(!events(0));
}

TEST_CASE("Elapsed signed integral called with start value returns zero", "[positive]") {
    auto events = elapsed<int>(0);
    REQUIRE(!events(0));
}
