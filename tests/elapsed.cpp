#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Elapsed unsigned integral called with start value returns zero", "[positive]") {
    auto events = elapsed<size_t>(0);
    REQUIRE(!events(0));
}
