#include "catch.hpp"
#include "rythm/counting.hpp"

TEST_CASE("Dropping only first and then always taking (three times)", "[positive]") {
    auto const drop_1 = drop_n(1);
    CHECK(!drop_1());
    CHECK(drop_1());
    CHECK(drop_1());
    REQUIRE(drop_1());
}
