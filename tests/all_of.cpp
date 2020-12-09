#include "../rythm/predicate.hpp"

TEST_CASE("All of only true values yields true", "[positive]") {
    bool const ct{true};
    bool t{true};
    REQUIRE(all_of(true, ct, true, t, true));
}
