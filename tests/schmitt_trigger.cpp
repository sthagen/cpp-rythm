#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Two probes across the thresholds", "[positive]") {
    auto const low = -1.f, high = 2.f;
    bool const default_out = false;
    auto st = schmitt_trigger<float>(low, high, default_out);
    CHECK(!st(0.f));
    REQUIRE(st(high + 1.f));
}
