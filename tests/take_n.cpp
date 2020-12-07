#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Taking only first and then always dropping (three times)", "[positive]") {
    auto take_1 = take_n(1);
    CHECK(take_1());
    CHECK(!take_1());
    CHECK(!take_1());
    REQUIRE(!take_1());
}
