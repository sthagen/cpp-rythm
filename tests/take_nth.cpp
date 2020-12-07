#include "catch.hpp"
#include "rythm/counting.hpp"

TEST_CASE("Taking only every third invocation (three periods check)", "[positive]") {
    auto const take_every_third = take_nth(3);
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    REQUIRE(take_every_third());
}