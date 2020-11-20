#pragma once

constexpr auto n_times = [](size_t n) { return [n]() mutable { return n ? n-- : 0; }; };
