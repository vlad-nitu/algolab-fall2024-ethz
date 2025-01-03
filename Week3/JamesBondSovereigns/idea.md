# Topics
- DP

# Idea
- `p_k` (only 1 player) maximizes his winnings, the passengers other than `p_k` (k - 1 others) minimize p_k's winnings. Thus, we need 2 states: `turn == 1 => It is p_k turn; else: turn == 0 => It is any player other than p_k's turn`.
- Implement recursively as it is easier to "simulate" the game and reason about it.
- During recursion, we can figure in which of the 2 states we are in by checking: `turn = (cnt == k)`, where `cnt` statrs from 0 and each recursion call it is incremented circularly as: `cnt = (cnt + 1) % m` to wrap around to `p_0`, after `p_(m-1)`'s turn.
- Recurrence relationship: `memo[turn][i][j] = largest winning that passenger p_k can collect when the passengers are still to pick from segment [i:j]`
```
      if (!turn) { // Passengers other than p_k try to minimise his winnings
        memo[turn][i][j] = min(dp(memo, v, n, m, (cnt + 1) % m, k, i + 1, j), // p_turn picks v[i]
                               dp(memo, v, n, m, (cnt + 1) % m, k, i, j - 1)); // p_turn picks v[j]
      }
      else { // p_k tries to maximize his winning
        memo[turn][i][j] = max(v[i] + dp(memo, v, n, m, (cnt + 1) % m, k, i + 1, j), // p_k picks v[i] -> add v[i] to final score
                               v[j] + dp(memo, v, n, m, (cnt + 1) % m, k, i, j - 1)); // p_k picks v[j] -> add v[j] to final score
      }
```

# Time Complexity
- Number of DP state: `2 * N * N`
- Time to take DP decision each iteration: `O(1)`
- => `O(N^2)` time
