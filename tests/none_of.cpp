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

TEST_CASE("None of a single false value yields true", "[positive]") {
    bool f{false};
    REQUIRE(none_of(f));
}

TEST_CASE("None of a none of a single true value yields true", "[positive]") {
    bool t{true};
    REQUIRE(none_of(none_of(t)));
}

TEST_CASE("None of two none ofs of single true values yields true", "[positive]") {
    bool t{true};
    REQUIRE(none_of(none_of(t), none_of(t)));
}

TEST_CASE("None of two any ofs of single true values yields false", "[positive]") {
    bool t{true};
    REQUIRE(!none_of(any_of(t), any_of(t)));
}

TEST_CASE("Zero if none of only a single true value does not zero the target", "[positive]") {
    bool t{true};
    double k{42.};
    REQUIRE(zero_if_all_of(k, t) == k);
}
