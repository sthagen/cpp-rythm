#pragma once

namespace schmitt {

template <class T>
constexpr auto trigger = [](T const low, T const high, bool initial_state) { 
    bool state = initial_state;
    return [low, high, state](T read) mutable { 
        return state = (read > high) || (state && !(read < low));
    }; 
};

template <class T>
constexpr auto trigger_inverting = [](T const low, T const high, bool initial_state) { 
    bool state = initial_state;
    return [low, high, state](T read) mutable { 
        return state = (read < low) || (state && !(read > high));
    }; 
};

} // namespace
