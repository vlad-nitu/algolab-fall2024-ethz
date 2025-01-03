# Topics
- DP based on SW or BS precomputation of the predecessor.

# Precomputation Idea 1: SW
- Use Sliding Window (SW) to obtain the predecessor of `defender[j]`, where the predecessor is defined as: `pred[j] = i <=> sum_def[i + 1 : j] == k` 
- We observe this can be solved w/ the SW technique, where the SW is expanded when `sum_def[i+1:j] < k` (j ++ right ptr), shrank when `sum_def[i+1:j] > k` (i ++ left ptr), and: marks `pred[j] = i` and shrinks SW (i ++) if `sum_def[i + 1:j] == k`.
- `sum_def[i + 1 : j]` is obtained in `O(1)` by using prefix sums as another precomputation: `sum_def[i + 1 : j] = sum_def[j] - sum_def[i]`.
- Precomputation of predecessor takes `O(N)` time.

# Precomputation Idea 2: BS
- `sum_def[i : j] = sum_def[j] - sum_def[i - 1] == k` <=> `target = k + sum_def[i - 1]` and use Binary Search([std::binary_search](https://en.cppreference.com/w/cpp/algorithm/binary_search)) to find `sum_def[j]` in `O(logN)` time for each `1 <= i <= n`
- Precomputation of predecessor takes `O(NlogN)` time.

# Idea: DP
- After applying either precomputation idea 1 OR 2, we obtain the same `pred` array.
- Now we can apply DP: m (#attackers) x n (#defenders) table: `dp[i][j] = max. value of a legal strategy after the first i attackers attack a subset of the first j defenders`; `1 <= i <= m && 1 <= j <= m`
```
 // Base case: No attackers (i == 0) attacking any defender (1 <= j <= n) get 0 points
    for (int j = 0; j <= n; j ++)
        dp[0][j] = 0;
// Recurrence equation
 for (int i = 1; i <= m; ++i) {
    for (int j = 1; j <= n; ++j) {
      int predec = pred[j]; 
      if (predec != -1 && dp[i-1][predec] != -1) {
      dp[i][j] = max(dp[i][j - 1],                    // [pred[j] + 1 : j] NOT attacked by attacker `i` 
                     (j - predec) + dp[i-1][predec]);  // [pred[j] + 1 : j] attacked by attacker `i`
      }
      else 
        dp[i][j] = dp[i][j - 1]; 
    }
  }
```
- Checking for feasibility: Check that no row contains only -1s, to ensure that all attackers attack at least one defender!.
- ANS (if feasible): `dp[m][n]`, as the max. value in DP is propagated "to the right" on the `not taken` case of the DP: `dp[i][j] = dp[i][j - 1]`


# Time complexity:
- `O(N*M)`; n <= 1e5 (defenders); m <= 100 (attackers)
