#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 2;
    std::cout << "Example: Using drop_nth(" << n << ") to drop every other " << n << " iteration.\n";
    auto drop_every_other = drop_nth(n);
    auto how_many = 0;
    while (drop_every_other()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many << " iterations.\n";
    while (drop_every_other()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many << " iterations.\n";
    return how_many == n * 2 ? 0 : 1;
}
