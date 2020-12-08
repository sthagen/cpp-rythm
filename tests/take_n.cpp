#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Taking none and always dropping (three times)", "[positive]") {
    auto take_0 = take_n(0);
    CHECK(!take_0());
    CHECK(!take_0());
    REQUIRE(!take_0());
}

TEST_CASE("Taking only first and then always dropping (three times)", "[positive]") {
    auto take_1 = take_n(1);
    CHECK(take_1());
    CHECK(!take_1());
    CHECK(!take_1());
    REQUIRE(!take_1());
}

TEST_CASE("Taking first two and then always dropping (three times)", "[positive]") {
    auto take_2 = take_n(2);
    CHECK(take_2());
    CHECK(take_2());
    CHECK(!take_2());
    CHECK(!take_2());
    REQUIRE(!take_2());
}

TEST_CASE("Taking first three and then always dropping (four times)", "[positive]") {
    auto take_3 = take_n(3);
    CHECK(take_3());
    CHECK(take_3());
    CHECK(take_3());
    CHECK(!take_3());
    CHECK(!take_3());
    CHECK(!take_3());
    REQUIRE(!take_3());
}
