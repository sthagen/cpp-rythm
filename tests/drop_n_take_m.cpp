#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Drop nothing and take 2 always alternating (checking three periods a 0 + 2)", "[negative]") {
    auto drop_0_take_2 = drop_n_take_m(0, 2);
    CHECK(drop_0_take_2());
    CHECK(drop_0_take_2());
    CHECK(!drop_0_take_2());
    CHECK(!drop_0_take_2());
    CHECK(!drop_0_take_2());
    REQUIRE(!drop_0_take_2());
    WARN("Unwanted behaviour detected for drop_n_take_m(0, 2) - always dropping after initial two takes.");
}

TEST_CASE("Drop one and take one always alternating (checking three periods a 1 + 1)", "[positive]") {
    auto drop_1_take_1 = drop_n_take_m(1, 1);
    CHECK(!drop_1_take_1());
    CHECK(drop_1_take_1());
    CHECK(!drop_1_take_1());
    CHECK(drop_1_take_1());
    CHECK(!drop_1_take_1());
    REQUIRE(drop_1_take_1());
}

TEST_CASE("Drop 1 and take 2 always alternating (checking three periods a 1 + 2)", "[positive]") {
    auto drop_1_take_2 = drop_n_take_m(1, 2);
    CHECK(!drop_1_take_2());
    CHECK(drop_1_take_2());
    CHECK(drop_1_take_2());
    
    CHECK(!drop_1_take_2());
    CHECK(drop_1_take_2());
    CHECK(drop_1_take_2());
    
    CHECK(!drop_1_take_2());
    CHECK(drop_1_take_2());
    REQUIRE(drop_1_take_2());
}

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
