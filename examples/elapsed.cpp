#include <iostream>
#include "../rythm/counting.hpp"

int main() {
    size_t const initial = 42;
    auto events = initial;
    std::cout << "Example: Using elapsed(" << initial << ") to create some counter and evaluating after " << events << " additional events.\n";
    auto count = elapsed<size_t>(event_counts);
    events += events;
    auto duration = count(events);
    std::cout << "Stopping after " << duration << " events.\n";
    return initial == duration ? 0 : 1;
}
