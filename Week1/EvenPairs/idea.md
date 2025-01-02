## Topics
- Partial sums, Combinatorics, basic math.

## Idea
- j < i: s[j + 1:i] = s[i] - s[j] is even if 1.) or 2.): 
1. s[i] even & s[j] even
2. s[i] odd & s[j] odd
- In O(N) (online), keep track of `pref_sum` which is s[0:i] when we reach the `i`th iteration. 
- 2 cases:
1. if `pref_sum = s[0:i]` even => match s[0:i] with all s[0:j], j < i s.t: s[0:j] is even, so that s[j+1:i] = s[0:i] - s[0:j] is (even - even) even
2. if `pref_sum = s[0:i]` odd => match s[0:i] with all s[0:j], j < i s.t: s[0:j] is odd, so that s[j+1:i] = s[0:i] - s[0:j] is (odd - odd) even 
- Thus, each time we find an even `pref_sum`, we increment the number of even prefix sums seen by this point: `evens_before`. Analogous for `odds_before`.
- Edge case: `evens_before = 1` initialised, to  allow counting s[0:i]; where j+1 = 0 => j = -1;
