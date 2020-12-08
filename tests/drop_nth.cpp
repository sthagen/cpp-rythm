#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Dropping no invocation (three periods check)", "[positive]") {
    auto drop_nothing = drop_nth(0);
    CHECK(drop_nothing());
    CHECK(drop_nothing());
    REQUIRE(drop_nothing());
}

TEST_CASE("Dropping every invocation (three periods check)", "[positive]") {
    auto drop_every = drop_nth(1);
    CHECK(!drop_every());
    CHECK(!drop_every());
    REQUIRE(!drop_every());
}

TEST_CASE("Dropping every other invocation (three periods check)", "[positive]") {
    auto drop_every_other = drop_nth(2);
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    CHECK(drop_every_other());
    CHECK(!drop_every_other());
    REQUIRE(drop_every_other());
}

TEST_CASE("Dropping every fourth invocation (three periods check)", "[positive]") {
    auto drop_every_fourth = drop_nth(4);
    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    CHECK(!drop_every_fourth());

    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    CHECK(!drop_every_fourth());

    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    CHECK(drop_every_fourth());
    REQUIRE(!drop_every_fourth());
}
