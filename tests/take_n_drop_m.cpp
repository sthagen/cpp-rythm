#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Take nothing and drop nothing always alternating (checking three times)", "[positive]") {
    auto take_0_drop0 = take_n_drop_m(0, 0);
    CHECK(!take_0_drop0());
    CHECK(!take_0_drop0());
    REQUIRE(!take_0_drop0());
    [[maybe_unused]] INFO("Note behaviour for take_n_drop_m(0, 0) - equivalent to take_n(0) and drop_n(1)");
}

TEST_CASE("Take nothing and drop everything always alternating (checking three times)", "[positive]") {
    auto take_0_drop_1 = take_n_drop_m(0, 1);
    CHECK(!take_0_drop_1());
    CHECK(!take_0_drop_1());
    REQUIRE(!take_0_drop_1());
    [[maybe_unused]] INFO("Note behaviour for take_n_drop_m(0, 1) - equivalent to take_n(0) and drop_n(1)");
}

TEST_CASE("Take nothing and drop 2 always alternating (checking three periods a 0 + 2)", "[positive]") {
    auto take_0_drop_2 = take_n_drop_m(0, 2);
    CHECK(!take_0_drop_2());
    CHECK(!take_0_drop_2());
    CHECK(!take_0_drop_2());
    CHECK(!take_0_drop_2());
    CHECK(!take_0_drop_2());
    REQUIRE(!take_0_drop_2());
    [[maybe_unused]] INFO("Note behaviour for take_n_drop_m(0, positive_integer) - equivalent to drop(1).");
}

TEST_CASE("Take 2 and drop nothing always alternating (checking three periods a 2 + 0)", "[positive]") {
    auto take_2_drop_0 = take_n_drop_m(2, 0);
    CHECK(take_2_drop_0());
    CHECK(take_2_drop_0());
    CHECK(take_2_drop_0());
    CHECK(take_2_drop_0());
    CHECK(take_2_drop_0());
    REQUIRE(take_2_drop_0());
    [[maybe_unused]] INFO("Note behaviour for take_n_drop_m(positive_integer, 0) - equivalent to take_n(1).");
}

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
