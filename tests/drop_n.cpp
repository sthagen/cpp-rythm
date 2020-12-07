#include "catch.hpp"
#include "../include/rythm/counting.hpp"

TEST_CASE("Dropping only first and then always taking (three times)", "[positive]") {
    auto drop_1 = drop_n(1);
    CHECK(!drop_1());
    CHECK(drop_1());
    CHECK(drop_1());
    REQUIRE(drop_1());
}
