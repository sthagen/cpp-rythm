#include "catch.hpp"
#include "rythm/counting.hpp"

TEST_CASE("Taking only upon every other invocation (three periods check)", "[positive]") {
    auto const drop_every_other = drop_nth(2);
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    REQUIRE(drop_every_other());
}