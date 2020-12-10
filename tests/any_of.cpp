#include "catch.hpp"
#include "../rythm/predicate.hpp"

TEST_CASE("Any of a single true and otherwise false values yields true", "[positive]") {
    bool const cf{false};
    bool t{true}, f{false};
    REQUIRE(any_of(false, cf, false, f, false, t));
}

TEST_CASE("Any of false values yields false", "[positive]") {
    bool const cf{false};
    bool f{false};
    REQUIRE(!any_of(false, cf, false, f, false));
}