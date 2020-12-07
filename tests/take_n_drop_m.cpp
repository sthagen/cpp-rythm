#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Take 1 and drop 1 always alternating (checking three periods a 1 + 1)", "[positive]") {
    auto take_1_drop_1 = take_n_drop_m(1, 1);
    CHECK(take_1_drop_1());
    CHECK(!take_1_drop_1());

    CHECK(take_1_drop_1());
    CHECK(!take_1_drop_1());

    CHECK(take_1_drop_1());
    REQUIRE(!take_1_drop_1());
}

TEST_CASE("Take 4 and drop 1 always alternating (checking three periods a 4 + 1)", "[positive]") {
    auto take_4_drop_1 = take_n_drop_m(4, 1);
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(!take_4_drop_1());
    
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(!take_4_drop_1());
    
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    CHECK(take_4_drop_1());
    REQUIRE(!take_4_drop_1());    
}
