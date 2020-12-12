#include <iostream>
#include "../rythm/predicate.hpp"

int main() {
    size_t const answer = 42;
    auto oh_no = 0;
    std::cout << "Example: Using none_of(" << answer << ", " << oh_no << ").\n";
    auto outcome = none_of(answer, oh_no);
    std::cout << "Outcome is " << outcome << ".\n";
    return !outcome ? 0 : 1;
}
