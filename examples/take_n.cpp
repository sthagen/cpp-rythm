#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 3;
    std::cout << "Example: Using take_n(" << n << ") to take the first " << n << " iterations.\n";
    auto take_3 = drop_n(n);
    auto how_many = 0;
    while (take_3()) {
        std::cout << "  " << ++how_many << ": Taking ...\n";
    }
    std::cout << "Dropping after " << how_many << " iterations.\n";
    return how_many == n ? 0 : 1;
}
