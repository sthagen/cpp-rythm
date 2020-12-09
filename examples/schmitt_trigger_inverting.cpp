#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto const low = -1.f, high = 2.f;
    bool const default_out = false;
    
    auto st = schmitt_trigger_inverting<float>(low, high, default_out);
   
    std::cout << "st.context("
              << low << ", " << high << ", " << default_out << "):\n";
    float m = 2., step = 1.f;
    auto cycles = 2;
    do {
        std::cout << "Rising ...\n";
        for (; m < high + step ; m += step) {
            std::cout << "  st(" << m << ") --> \t" << st(m) << "\n";
        }
        std::cout << "  st(" << m << ") --> \t" << st(m) << "\n";
        std::cout << "Sinking ...\n";
        for (; m > low - step; m -= step) {
            std::cout << "  st(" << m << ") --> \t" << st(m) << "\n";
        }
        std::cout << "  st(" << m << ") --> \t" << st(m) << "\n";
    } while (--cycles);
    return 0;
}
