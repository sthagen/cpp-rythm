#pragma once
/*
  Schmitt Trigger
  ===============
  
  A Schmitt trigger implements a hysteresis by applying positive feedback to the noninverting input. 
  The function is a "trigger" because the output retains its value until the input changes sufficiently 
  to trigger a change. 
  
  > In the non-inverting configuration, when the input is higher than a chosen threshold, the output is high. 
  > When the input is below a different (lower) chosen threshold the output is low, and when the input is 
  > between the two levels the output retains its value. 
  > This dual threshold action is called hysteresis and implies that the Schmitt trigger possesses memory 
  > and can act as a bistable multivibrator (latch or flip-flop). 
  > There is a close relation between the two kinds of circuits: 
  >   a Schmitt trigger can be converted into a latch and a latch can be converted into a Schmitt trigger.
                                                        (cf. https://en.wikipedia.org/wiki/Schmitt_trigger)
*/
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
