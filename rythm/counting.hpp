#pragma once

// Yield false for the first n calls and then true for every subsequent call.
constexpr auto drop_n = [](auto n) { return [n]() mutable { return n ? !n-- : true; }; };

// Yield true for the first n calls and then false for every subsequent call.
constexpr auto take_n = [](auto n) { return [n]() mutable { return n ? !!n-- : false; }; };

// Yield false every nth call and true for every other call.
constexpr auto drop_nth = [](auto n) { 
    auto period = n; return [period, n]() mutable { return !!--( n ? n : n = period); }; };

// Yield true every nth call and false for every other call.
constexpr auto take_nth = [](auto n) { 
    auto period = n; return [period, n]() mutable { return !--( n ? n : n = period); }; };

// Yield alternating false for n calls and then true for m calls.
constexpr auto drop_n_take_m = [](auto const off, auto const on) { 
    auto n = off + 1, m = on;
    auto active = false;
    if (!off && on) { n = -1, m = -1, active = true; }
    else if (off && !on) { n = -1, m = -1, active = false; };
    return [off, on, active, n, m]() mutable { 
        return active ? !--m && (active = !active, (m = on))
                      : !--n && (active = !active, (n = off))
                      , active;
    }; 
};

// Yield alternating true for n calls and then false for m calls.
constexpr auto take_n_drop_m = [](auto const on, auto const off) { 
    auto n = off, m = on + 1;
    auto active = true;
    if (!off && on) { n = -1, m = -1, active = true; }
    else if (off && !on) { n = -1, m = -1, active = false; };
    return [off, on, active, n, m]() mutable { 
        return active ? !--m && (active = !active, (m = on))
                      : !--n && (active = !active, (n = off))
                      , active;
    }; 
};

// Yield difference of argument to start value.
template<typename T>
constexpr auto elapsed = [](T const start) {
    return [start](T const stop) { return stop - start; }; };

template<typename A>
constexpr auto count_true = [](A a = A{0}) { auto _a{a}; return [_a](auto c) mutable { return c ? ++_a : _a; }; };

template<typename A>
constexpr auto count_false = [](A a = A{0}) { auto _a{a}; return [_a](auto c) mutable { return !c ? ++_a : _a; }; };

template<typename A, typename Z>
constexpr auto count_zero = [](A a = A{0}) { auto _a{a}; return [_a](Z z) mutable { return z == Z{0} ? ++_a : _a; }; };

template<typename P, typename A>
constexpr auto count_if = [](P p, A a = A{0}) { auto _a{a}; return [p, _a](auto c) mutable { return p(c) ? ++_a : _a; }; };

template<typename P, typename A>
constexpr auto count_else = [](P p, A a = A{0}) { auto _a{a}; return [p, _a](auto c) mutable { return !p(c) ? ++_a : _a; }; };
