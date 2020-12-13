#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    auto const threshold{5};
    auto more_than_five = [](auto x){ return x > threshold;};
    auto small_cases = count_else<decltype(more_than_five), size_t>(more_than_five);
    auto predicate{"more_than_five"};
    std::cout << "Example: Using count_else(" << predicate << ",).\n";
    auto outcome = small_cases(threshold + 1);
    std::cout << "Outcome is " << outcome << ".\n";
    return !outcome ? 0 : 1;
}
