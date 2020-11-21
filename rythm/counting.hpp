#pragma once

constexpr auto n_ramp = [](size_t n) { return [n]() mutable { return n ? n-- : 0; }; };

constexpr auto n_sawtooth = [](size_t n) { 
    auto period = n; return [period, n]() mutable { return !--( n ? n : n = period); }; }
