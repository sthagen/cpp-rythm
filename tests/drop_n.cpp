#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Dropping only first and then always taking (three times)", "[positive]") {
    auto drop_1 = drop_n(1);
    CHECK(!drop_1());
    CHECK(drop_1());
    CHECK(drop_1());
    REQUIRE(drop_1());
}

TEST_CASE("Dropping first three and then always taking (four times)", "[positive]") {
    auto drop_3 = drop_n(3);
    CHECK(!drop_3());
    CHECK(!drop_3());
    CHECK(!drop_3());
    CHECK(drop_1());
    CHECK(drop_1());
    CHECK(drop_1());
    REQUIRE(drop_1());
}
