#pragma once

constexpr auto drop_n = [](auto n) { return [n]() mutable { return n ? !n-- : true; }; };

constexpr auto take_n = [](auto n) { return [n]() mutable { return n ? !!n-- : false; }; };

constexpr auto drop_nth = [](auto n) { 
    auto period = n; return [period, n]() mutable { return !!--( n ? n : n = period); }; };

constexpr auto take_nth = [](auto n) { 
    auto period = n; return [period, n]() mutable { return !--( n ? n : n = period); }; };

constexpr auto drop_n_take_m = [](auto const off, auto const on) { 
    auto n = off + 1, m = on;
    auto active = false;
    if (!off && on) { n = -1, m = -1, active = true; };
    if (off && !on) { n = -1, m = -1, active = false; };
    return [off, on, active, n, m]() mutable { 
        return active ? !--m && (active = !active, (m = on))
                      : !--n && (active = !active, (n = off))
                      , active;
    }; 
};

constexpr auto take_n_drop_m = [](auto const on, auto const off) { 
    auto n = off, m = on + 1;
    auto active = true;
    if (!off && on) { n = -1, m = -1, active = false; };
    if (off && !on) { n = -1, m = -1, active = true; };
    return [off, on, active, n, m]() mutable { 
        return active ? !--m && (active = !active, (m = on))
                      : !--n && (active = !active, (n = off))
                      , active;
    }; 
};
