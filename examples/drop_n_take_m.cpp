#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 2, m = 1;
    std::cout << "Example: Using drop_n_take_m(" << n << ", " << m << ") to drop " << n << " then take " << m << " forever alternating.\n";
    auto drop_2_take_1 = drop_n_take_m(n, m);
    auto how_many = 0;
    while (drop_2_take_1()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many++ << " iterations.\n";
    while (drop_2_take_1()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many++ << " iterations.\n";
    return how_many == (n + m) * 2 ? 0 : 1;
}
