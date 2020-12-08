#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto n = 2;
    std::cout << "Example: Using drop_n(" << n << ") to drop the first " << n << " iterations.\n";
    auto drop_2 = drop_n(2);
    auto how_many = 0;
    while (!drop_2()) {
        std::cout << "  " << ++how_many << ": Dropping ...\n";
    }
    std::cout << "Taking after " << how_many << " iterations.\n";
    return how_many == n ? 0 : 1;
}
