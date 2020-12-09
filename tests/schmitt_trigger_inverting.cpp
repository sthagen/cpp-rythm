#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Two probes across the thresholds for the inverted trigger (once)", "[positive]") {
    auto const low = -1.f, high = 2.f;
    bool const default_out = true;
    auto st = schmitt_trigger_inverting<float>(low, high, default_out);
    CHECK(st(0.f));
    REQUIRE(!st(high + 1.f));
}
