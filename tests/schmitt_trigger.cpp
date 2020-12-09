#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Two probes across the thresholds", "[positive]") {
    auto const low = -1.f, high = 2.f;
    bool const default_out = false;
    auto st = schmitt_trigger<float>(low, high, default_out);
    CHECK(!st(0.f));
    REQUIRE(st(high + 1.f));
}

TEST_CASE("Cycling (once)", "[positive]") {
    auto const low = 1.f, high = 2.f;
    bool const default_out = false;
    auto st = schmitt_trigger<float>(low, high, default_out);
    float m = 2., step = 1.f;
    auto cycles = 1;
    do {
        INFO("Rising ...");
        bool expected_state = false;
        for (; m < high + step ; m += step) {
            CHECK(st(m) == expected_state);
            expected_state = true;
        }
        CHECK(st(m) == expected_state);
        INFO("Sinking ...");
        for (; m > low - step; m -= step) {
            CHECK(st(m) == expected_state);
        }
        expected_state = false;
        REQUIRE(st(m) == expected_state);
    } while (--cycles);
}
