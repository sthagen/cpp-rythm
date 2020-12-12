#include "catch.hpp"
#include "../rythm/predicate.hpp"

TEST_CASE("All of only true values yields true", "[positive]") {
    bool const ct{true};
    bool t{true};
    REQUIRE(all_of(true, ct, true, t, true));
}

TEST_CASE("All of a single integral value wun yields true", "[positive]") {
    int t{1};
    REQUIRE(all_of(t));
}

TEST_CASE("All of a single integral value zero yields false", "[positive]") {
    int f{0};
    REQUIRE(!all_of(f));
}

TEST_CASE("All of not only true values yields false", "[positive]") {
    bool const ct{true};
    bool t{true}, f{false};
    REQUIRE(!all_of(true, ct, true, t, true, f));
}

TEST_CASE("All of a single true value yields true", "[positive]") {
    bool t{true};
    REQUIRE(all_of(t));
}

TEST_CASE("All of a single false value yields false", "[positive]") {
    bool f{false};
    REQUIRE(!all_of(f));
}

TEST_CASE("All of an all of a single true value yields true", "[positive]") {
    bool t{true};
    REQUIRE(all_of(all_of(t)));
}

TEST_CASE("All of two all ofs of single true values yields true", "[positive]") {
    bool t{true};
    REQUIRE(all_of(all_of(t), all_of(t)));
}

TEST_CASE("All of two any ofs of single true values yields true", "[positive]") {
    bool t{true};
    REQUIRE(all_of(any_of(t), any_of(t)));
}

TEST_CASE("All of two none ofs of single true values yields false", "[positive]") {
    bool t{true};
    REQUIRE(!all_of(none_of(t), none_of(t)));
}

TEST_CASE("Zero if all of only a single true value zeroes the target", "[positive]") {
    using namespace Catch::literals;
    bool t{true};
    double k{42.};
    REQUIRE(zero_if_all_of(k, t) == 0._a);
}

TEST_CASE("Other if all of only a single true value sets the target to the other value", "[positive]") {
    bool t{true};
    double k{42.}, o{3.14156};
    REQUIRE(other_if_all_of(k, o, t) == o);
}
