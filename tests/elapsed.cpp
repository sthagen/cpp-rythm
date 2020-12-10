#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Elapsed unsigned integral called with start value returns zero", "[positive]") {
    auto events = elapsed<size_t>(0);
    REQUIRE(!events(0));
}

TEST_CASE("Elapsed signed integral called with start value returns zero", "[positive]") {
    auto events = elapsed<int>(0);
    REQUIRE(!events(0));
}

TEST_CASE("Elapsed float called with start value returns zero", "[positive]") {
    using namespace Catch::literals;
    auto events = elapsed<float>(0.f);
    REQUIRE(events(0.f) == 0.0_a);
}

TEST_CASE("Elapsed double called with start value returns zero", "[positive]") {
    using namespace Catch::literals;
    auto events = elapsed<double>(0.);
    REQUIRE(events(0.) == 0.0_a);
}

TEST_CASE("Elapsed unsigned integral called with start value plus wun returns returns wun", "[positive]") {
    auto events = elapsed<size_t>(0);
    REQUIRE(events(1) == 1);
}

TEST_CASE("Elapsed signed integral called with start value plus wun returns returns wun", "[positive]") {
    auto events = elapsed<int>(0);
    REQUIRE(events(1) == 1);
}

TEST_CASE("Elapsed float called with start value returns plus wun returns returns wun", "[positive]") {
    using namespace Catch::literals;
    auto events = elapsed<float>(0.f);
    REQUIRE(events(1.f) == 1.0_a);
}

TEST_CASE("Elapsed double called with start value returns plus wun returns returns wun", "[positive]") {
    using namespace Catch::literals;
    auto events = elapsed<double>(0.);
    REQUIRE(events(1.) == 1.0_a);
}
