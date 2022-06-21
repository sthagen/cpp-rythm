# cpp-rythm

Header only behavior library

## Usage

Generate build files:

```console
❯ cmake -S . -B build
# ...
```

Build (in parallel):

```console
❯ cmake --build build --parallel 4
[  8%] Building CXX object examples/CMakeFiles/any_of.dir/any_of.cpp.o
[  8%] Building CXX object tests/CMakeFiles/rythm_test.dir/test.cpp.o
[  8%] Building CXX object examples/CMakeFiles/count_else.dir/count_else.cpp.o
[  8%] Building CXX object examples/CMakeFiles/all_of.dir/all_of.cpp.o
[ 11%] Linking CXX executable all_of
[ 15%] Linking CXX executable count_else
[ 15%] Linking CXX executable any_of
[ 15%] Built target all_of
[ 15%] Built target any_of
[ 15%] Built target count_else
[ 17%] Building CXX object tests/CMakeFiles/rythm_test.dir/all_of.cpp.o
[ 20%] Building CXX object examples/CMakeFiles/none_of.dir/none_of.cpp.o
[ 22%] Building CXX object examples/CMakeFiles/drop_n.dir/drop_n.cpp.o
[ 26%] Linking CXX executable drop_n
[ 26%] Linking CXX executable none_of
[ 26%] Built target none_of
[ 26%] Built target drop_n
[ 28%] Building CXX object tests/CMakeFiles/rythm_test.dir/any_of.cpp.o
[ 31%] Building CXX object examples/CMakeFiles/take_n.dir/take_n.cpp.o
[ 33%] Building CXX object examples/CMakeFiles/drop_nth.dir/drop_nth.cpp.o
[ 35%] Linking CXX executable take_n
[ 37%] Linking CXX executable drop_nth
[ 37%] Built target drop_nth
[ 37%] Built target take_n
[ 40%] Building CXX object tests/CMakeFiles/rythm_test.dir/none_of.cpp.o
[ 42%] Building CXX object examples/CMakeFiles/drop_n_take_m.dir/drop_n_take_m.cpp.o
[ 44%] Building CXX object examples/CMakeFiles/take_nth.dir/take_nth.cpp.o
[ 48%] Linking CXX executable drop_n_take_m
[ 48%] Linking CXX executable take_nth
[ 48%] Built target drop_n_take_m
[ 48%] Built target take_nth
[ 51%] Building CXX object tests/CMakeFiles/rythm_test.dir/drop_n.cpp.o
[ 53%] Building CXX object tests/CMakeFiles/rythm_test.dir/take_n.cpp.o
[ 55%] Building CXX object examples/CMakeFiles/take_n_drop_m.dir/take_n_drop_m.cpp.o
[ 57%] Linking CXX executable take_n_drop_m
[ 57%] Built target take_n_drop_m
[ 60%] Building CXX object tests/CMakeFiles/rythm_test.dir/drop_nth.cpp.o
[ 62%] Building CXX object examples/CMakeFiles/schmitt_trigger.dir/schmitt_trigger.cpp.o
[ 64%] Building CXX object examples/CMakeFiles/schmitt_trigger_inverting.dir/schmitt_trigger_inverting.cpp.o
[ 68%] Linking CXX executable schmitt_trigger
[ 68%] Linking CXX executable schmitt_trigger_inverting
[ 71%] Building CXX object tests/CMakeFiles/rythm_test.dir/take_nth.cpp.o
[ 71%] Built target schmitt_trigger_inverting
[ 71%] Built target schmitt_trigger
[ 73%] Building CXX object tests/CMakeFiles/rythm_test.dir/drop_n_take_m.cpp.o
[ 75%] Building CXX object examples/CMakeFiles/elapsed.dir/elapsed.cpp.o
[ 77%] Linking CXX executable elapsed
[ 77%] Built target elapsed
[ 80%] Building CXX object tests/CMakeFiles/rythm_test.dir/take_n_drop_m.cpp.o
[ 82%] Building CXX object tests/CMakeFiles/rythm_test.dir/elapsed.cpp.o
[ 84%] Building CXX object tests/CMakeFiles/rythm_test.dir/count_true.cpp.o
[ 86%] Building CXX object tests/CMakeFiles/rythm_test.dir/count_false.cpp.o
[ 88%] Building CXX object tests/CMakeFiles/rythm_test.dir/count_zero.cpp.o
[ 91%] Building CXX object tests/CMakeFiles/rythm_test.dir/count_if.cpp.o
[ 93%] Building CXX object tests/CMakeFiles/rythm_test.dir/count_else.cpp.o
[ 95%] Building CXX object tests/CMakeFiles/rythm_test.dir/schmitt_trigger.cpp.o
[ 97%] Building CXX object tests/CMakeFiles/rythm_test.dir/schmitt_trigger_inverting.cpp.o
[100%] Linking CXX executable rythm_test
[100%] Built target rythm_test
```

Execute tests:

```console
❯ build/tests/rythm_test
===============================================================================
All tests passed (281 assertions in 108 test cases)
```

### Execute examples:

All of:

```console
❯ build/examples/all_of
Example: Using all_of(42, 0).
Outcome is 0.
```

Any of:

```console
❯ build/examples/any_of
Example: Using any_pf(42, 0).
Outcome is 1.
```

None of:

```console
❯ build/examples/none_of
Example: Using none_of(42, 0).
Outcome is 0.
```

Count Else:

```console
❯ build/examples/count_else
Example: Using count_else(more_than_five,).
Outcome is 0.
```

Elapsed:

```console
❯ build/examples/elapsed
Example: Using elapsed(42) to create some counter and evaluating after 42 additional events.
Stopping after 42 events.
```

Drop N:

```console
❯ build/examples/drop_n
Example: Using drop_n(2) to drop the first 2 iterations.
  1: Dropping ...
  2: Dropping ...
Taking after 2 iterations.
```

Drop nth:

```console
❯ build/examples/drop_nth
Example: Using drop_nth(2) to drop every 2. iteration.
  1: Dropping ...
Taking after 1 iterations.
  3: Dropping ...
Taking after 3 iterations.
```

Drop N Take M:

```console
❯ build/examples/drop_n_take_m
Example: Using drop_n_take_m(2, 1) to drop 2 then take 1 forever alternating.
  1: Dropping ...
  2: Dropping ...
Taking after 2 iterations.
  4: Dropping ...
  5: Dropping ...
Taking after 5 iterations.
```

Take N:

```console
❯ build/examples/take_n
Example: Using take_n(3) to take the first 3 iterations.
  1: Taking ...
  2: Taking ...
  3: Taking ...
Dropping after 3 iterations.
```

Take nth:

```console
❯ build/examples/take_nth
Example: Using take_nth(3) to take every 3. iteration.
  1: Dropping ...
  2: Dropping ...
Taking after 2 iterations.
  4: Dropping ...
  5: Dropping ...
Taking after 5 iterations.
```

Take N Drop M:

```console
❯ build/examples/take_n_drop_m
Example: Using take_n_drop_m(3, 2) to take 3 then drop 2 forever alternating.
  1: Taking ...
  2: Taking ...
  3: Taking ...
Dropping after 3 iterations.
  5: Continued dropping ...
Taking after 5 iterations.
  7: Continued taking ...
  8: Continued taking ...
Dropping after 8 iterations.
  10: Continued dropping ...
```

Schmitt trigger:

```console
❯ build/examples/schmitt_trigger
st.context(-1, 2, 0):
Rising ...
  st(2) --> 	0
  st(3) --> 	1
Sinking ...
  st(3) --> 	1
  st(2) --> 	1
  st(1) --> 	1
  st(0) --> 	1
  st(-1) --> 	1
  st(-2) --> 	0
Rising ...
  st(-2) --> 	0
  st(-1) --> 	0
  st(0) --> 	0
  st(1) --> 	0
  st(2) --> 	0
  st(3) --> 	1
Sinking ...
  st(3) --> 	1
  st(2) --> 	1
  st(1) --> 	1
  st(0) --> 	1
  st(-1) --> 	1
  st(-2) --> 	0
```

Inverting Schmitt trigger:

```console
❯ build/examples/schmitt_trigger_inverting
st.context(-1, 2, 0):
Rising ...
  st(2) --> 	0
  st(3) --> 	0
Sinking ...
  st(3) --> 	0
  st(2) --> 	0
  st(1) --> 	0
  st(0) --> 	0
  st(-1) --> 	0
  st(-2) --> 	1
Rising ...
  st(-2) --> 	1
  st(-1) --> 	1
  st(0) --> 	1
  st(1) --> 	1
  st(2) --> 	1
  st(3) --> 	0
Sinking ...
  st(3) --> 	0
  st(2) --> 	0
  st(1) --> 	0
  st(0) --> 	0
  st(-1) --> 	0
  st(-2) --> 	1
```

## Status

Experimental

**Note**: The default branch is `default`.
