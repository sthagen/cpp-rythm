#include "catch.hpp"
#include "../rythm/counting.hpp"

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
