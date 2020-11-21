#pragma once

constexpr auto drop_n = [](auto n) { return [n]() mutable { return n ? !n-- : true; }; };
constexpr auto take_n = [](auto n) { return [n]() mutable { return n ? !!n-- : false; }; };
