#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 3;
    std::cout << "Example: Using take_nth(" << n << ") to take every " << n << ". iteration.\n";
    auto take_every_third = take_nth(n);
    auto how_many = 0;
    while (!take_every_third()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many++ << " iterations.\n";
    while (!take_every_third()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many++ << " iterations.\n";
    return how_many == n * 2 ? 0 : 1;
}
