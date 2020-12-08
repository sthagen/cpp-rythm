#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto drop_2 = drop_n(2);
    auto how_many = 0;
    while (!drop_2()) {
        std::cout << "Iteration " << ++how_many << "\n";
    }
    std::cout << Finished after " << how_many << " iterations.\n";
    return how_many == 2 ? 0 : 1;
}
