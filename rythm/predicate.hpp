#pragma once
/*
  Predicate Operations Powered by Folding
  =======================================
  (cf. https://foonathan.net/2020/05/fold-tricks/)

  Call a function with each element
  ---------------------------------

  for (auto elem : ts)
    f(elem);

  (f(ts), ...);
  // expands to: f(ts[0]), f(ts[1]), f(ts[2]), ...

  Call a function with each element in reverse order
  --------------------------------------------------

  for (auto elem : reversed(ts))
    f(elem);

  int dummy;
  (dummy = ... = (f(ts), 0));
  // expands to: dummy = ((f(ts[0]), 0) = (f(ts[1]), 0)) = ...


  Call a function with each element until a predicate matches 
  -----------------------------------------------------------
  
  for (auto elem : ts) {
      if (pred(elem))
          break;
      f(elem);
  }  

  ((pred(ts) ? false : (f(ts), true)) && ...);
  // expands to: (pred(ts[0]) ? false : (f(ts[0]), true)) 
  //              && (pred(ts[1]) ? false : (f(ts[1]), true))
  //              && ...

  Check whether any element matches a predicate
  ---------------------------------------------
  
  for (auto elem : ts)
    if (pred(elem))
      return true;
  return false;
  
  bool any_of = (pred(ts) || ...);
  // expands to: pred(ts[0]) || pred(ts[1]) || ...
  
  Count how many elements match a predicate
  -----------------------------------------
  
  std::size_t count = 0;
  for (auto elem : ts)
    if (pred(elem))
      ++count;

  auto count = (std::size_t(0) + ... + (pred(ts) ? 1 : 0));
  // expands to: std::size_t(0) + (pred(ts[0]) ? 1 : 0)
  //                            + (pred(ts[1]) ? 1 : 0)
  //                            + ...

  Find the first element that matches the predicate
  -------------------------------------------------

  for (auto elem : ts) {
    if (pred(elem))
        return elem;
  }
  // not found

  std::common_type_t<decltype(ts)...> result;
  bool found = ((pred(ts) ? (result = ts, true) : false) || ...);
  // expands to: (pred(ts[0]) ? (result = ts[0], true) : false)
  //          || (pred(ts[1]) ? (result = ts[1], true) : false)
  //          || ...


*/

template<typename... T>
bool all_of(T... t) { return (... && t); }

template<typename... T>
bool any_of(T... t) { return (... || t); }

template<typename... T>
bool none_of(T... t) { return !(... || t); }

template<typename K, typename... T>
K zero_if_all_of(K k, T... t) { return (... && t) ? K{0} : k; }

template<typename K, typename... T>
K zero_if_any_of(K k, T... t) { return (... || t) ? K{0} : k; }

template<typename K, typename... T>
K zero_if_none_of(K k, T... t) { return !(... || t) ? K{0} : k; }

template<typename K, typename... T>
K other_if_all_of(K k, K o, T... t) { return (... && t) ? o : k; }
