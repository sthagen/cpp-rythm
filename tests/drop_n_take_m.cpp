#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Drop 2 and take 3 always alternating (checking three periods a 2 + 3)", "[positive]") {
    auto drop_2_take_3 = drop_n_take_m(2, 3);
    CHECK(!drop_2_take_3());
    CHECK(!drop_2_take_3());
    CHECK(drop_2_take_3());
    CHECK(drop_2_take_3());
    CHECK(drop_2_take_3());
    
    CHECK(!drop_2_take_3());
    CHECK(!drop_2_take_3());
    CHECK(drop_2_take_3());
    CHECK(drop_2_take_3());
    CHECK(drop_2_take_3());

    CHECK(!drop_2_take_3());
    CHECK(!drop_2_take_3());
    CHECK(drop_2_take_3());
    CHECK(drop_2_take_3());
    REQUIRE(drop_2_take_3());
}
