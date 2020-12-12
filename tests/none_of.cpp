#include "catch.hpp"
#include "../rythm/predicate.hpp"

TEST_CASE("None of only true values yields false", "[positive]") {
    bool const ct{true};
    bool t{true};
    REQUIRE(!none_of(true, ct, true, t, true));
}
