#include "catch.hpp"
#include "../rythm/counting.hpp"

TEST_CASE("Count false for true does not increment", "[positive]") {
    auto failures = count_false<size_t>();
    REQUIRE(failures(true) == 0);
}

TEST_CASE("Count false for false does increment", "[positive]") {
    auto failures = count_false<size_t>();
    REQUIRE(failures(false) == 1);
}

TEST_CASE("Count false for true and then false does increment once", "[positive]") {
    auto failures = count_false<size_t>();
    CHECK(failures(true) == 0);
    REQUIRE(failures(false) == 1);
}
