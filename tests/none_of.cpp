#include "catch.hpp"
#include "../rythm/predicate.hpp"

TEST_CASE("None of only true values yields false", "[positive]") {
    bool const ct{true};
    bool t{true};
    REQUIRE(!none_of(true, ct, true, t, true));
}

TEST_CASE("None of not only true values yields false", "[positive]") {
    bool const ct{true};
    bool t{true}, f{false};
    REQUIRE(!none_of(true, ct, true, t, true, f));
}

TEST_CASE("None of a single integral value wun yields false", "[positive]") {
    int t{1};
    REQUIRE(!none_of(t));
}

TEST_CASE("None of a single integral value zero yields true", "[positive]") {
    int f{0};
    REQUIRE(none_of(f));
}

TEST_CASE("None of a single true value yields false", "[positive]") {
    bool t{true};
    REQUIRE(!none_of(t));
}
