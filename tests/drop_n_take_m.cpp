#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Drop nothing and take nothing always alternating (checking three times)", "[positive]") {
    auto drop_0_take_0 = drop_n_take_m(0, 0);
    CHECK(drop_0_take_0());
    CHECK(drop_0_take_0());
    REQUIRE(drop_0_take_0());
    INFO("Note behaviour for drop_n_take_m(0, 0) - equivalent to drop_n(0) and take_n(1)");
}

TEST_CASE("Drop nothing and take everything always alternating (checking three times)", "[positive]") {
    auto drop_0_take_1 = drop_n_take_m(0, 1);
    CHECK(drop_0_take_1());
    CHECK(drop_0_take_1());
    REQUIRE(drop_0_take_1());
    INFO("Note behaviour for drop_n_take_m(0, 1) - equivalent to drop_n(0) and take_n(1)");
}

TEST_CASE("Drop nothing and take 2 always alternating (checking three periods a 0 + 2)", "[positive]") {
    auto drop_0_take_2 = drop_n_take_m(0, 2);
    CHECK(drop_0_take_2());
    CHECK(drop_0_take_2());
    CHECK(drop_0_take_2());
    CHECK(drop_0_take_2());
    CHECK(drop_0_take_2());
    REQUIRE(drop_0_take_2());
    INFO("Note behaviour for drop_n_take_m(0, positive_integer) - equivalent to take_n(1).");
}

TEST_CASE("Drop 2 and take nothing always alternating (checking three periods a 2 + 0)", "[positive]") {
    auto drop_2_take_0 = drop_n_take_m(2, 0);
    CHECK(!drop_2_take_0());
    CHECK(!drop_2_take_0());
    CHECK(!drop_2_take_0());
    CHECK(!drop_2_take_0());
    CHECK(!drop_2_take_0());
    REQUIRE(!drop_2_take_0());
    INFO("Note behaviour for drop_n_take_m(positive_integer, 0) - equivalent to drop_n(1).");
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
