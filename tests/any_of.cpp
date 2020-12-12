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

TEST_CASE("Any of not only true values yields true", "[positive]") {
    bool const ct{true};
    bool t{true}, f{false};
    REQUIRE(any_of(true, ct, true, t, true, f));
}

TEST_CASE("Any of a single integral value wun yields true", "[positive]") {
    int t{1};
    REQUIRE(any_of(t));
}

TEST_CASE("Any of a single integral value zero yields false", "[positive]") {
    int f{0};
    REQUIRE(!any_of(f));
}

TEST_CASE("Any of a single true value yields true", "[positive]") {
    bool t{true};
    REQUIRE(any_of(t));
}

TEST_CASE("Any of a single false value yields false", "[positive]") {
    bool f{false};
    REQUIRE(!any_of(f));
}

TEST_CASE("Any of an any of a single true value yields true", "[positive]") {
    bool t{true};
    REQUIRE(any_of(any_of(t)));
}

TEST_CASE("Any of two any ofs of single true values yields true", "[positive]") {
    bool t{true};
    REQUIRE(any_of(any_of(t), any_of(t)));
}

TEST_CASE("Any of two all ofs of single true values yields true", "[positive]") {
    bool t{true};
    REQUIRE(any_of(all_of(t), all_of(t)));
}

TEST_CASE("Any of two mone ofs of single true values yields false", "[positive]") {
    bool t{true};
    REQUIRE(!any_of(none_of(t), none_of(t)));
}
