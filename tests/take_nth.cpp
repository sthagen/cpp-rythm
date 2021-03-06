#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Taking no invocation (three periods check)", "[positive]") {
    auto take_nothing = take_nth(0);
    CHECK(!take_nothing());
    CHECK(!take_nothing());
    REQUIRE(!take_nothing());
}

TEST_CASE("Taking every invocation (three periods check)", "[positive]") {
    auto take_every = take_nth(1);
    CHECK(take_every());
    CHECK(take_every());
    REQUIRE(take_every());
}

TEST_CASE("Taking every other invocation (three periods check)", "[positive]") {
    auto take_every_other = take_nth(2);
    CHECK(!take_every_other());
    CHECK(take_every_other());
    CHECK(!take_every_other());
    CHECK(take_every_other());
    CHECK(!take_every_other());
    REQUIRE(take_every_other());
}

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
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(take_every_fifth());

    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(take_every_fifth());

    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    CHECK(!take_every_fifth());
    REQUIRE(take_every_fifth());
}
