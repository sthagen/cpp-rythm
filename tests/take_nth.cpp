#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Taking only every third invocation (three periods check)", "[positive]") {
    auto take_every_third = take_nth(3);
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

TEST_CASE("Taking every fifth invocation (three periods check)", "[positive]") {
    auto take_every_fifth = take_nth(5);
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(take_every_third());

    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(take_every_third());

    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    CHECK(!take_every_third());
    REQUIRE(take_every_third());
}
