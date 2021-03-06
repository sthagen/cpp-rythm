#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 3, m = 2;
    std::cout << "Example: Using take_n_drop_m(" << n << ", " << m << ") to take " << n << " then drop " << m << " forever alternating.\n";
    auto take_3_drop_2 = take_n_drop_m(n, m);
    auto how_many = 0;
    while (take_3_drop_2()) {
        std::cout << "  " << ++how_many << ": Taking ...\n";
    }
    std::cout << "Dropping after " << how_many++ << " iterations.\n";
    while (!take_3_drop_2()) {
        std::cout << "  " << ++how_many << ": Continued dropping ...\n";
    }
    std::cout << "Taking after " << how_many++ << " iterations.\n";
    while (take_3_drop_2()) {
        std::cout << "  " << ++how_many << ": Continued taking ...\n";
    }
    std::cout << "Dropping after " << how_many++ << " iterations.\n";
    while (!take_3_drop_2()) {
        std::cout << "  " << ++how_many << ": Continued dropping ...\n";
    }
    return how_many == (n + m) * 2 ? 0 : how_many;
}
