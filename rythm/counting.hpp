#pragma once

constexpr auto n_ramp = [](auto n) { return [n]() mutable { return n ? n-- : 0; }; };

constexpr auto n_sawtooth = [](auto n) { 
    auto period = n; return [period, n]() mutable { return !--( n ? n : n = period); }; }
