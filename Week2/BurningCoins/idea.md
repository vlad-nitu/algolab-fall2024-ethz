# Topics
- DP (pretty straight forward). 

# Idea
- `dp[i][j] = max. amount of money I win when we still have to play [i:j] segment of coins, and I start; 1 <= i,j <= n` 
- Recurrence relationship: 
```
 if (i == j) { // Base case -> only 1 coin to pick
     if (my_turn)
       memo[i][j] = v[i];
     else
       memo[i][j] = 0;
     return memo[i][j];
 }

 if (my_turn) { // I maximize my score
    memo[i][j] = max(v[i] + dp(memo, v, i + 1, j, !my_turn), // I pick v[i] if this will maximize MY winnigs.
                     v[j] + dp(memo, v, i, j - 1, !my_turn)); // I pick v[j] if this will maximize MY winnigs.
  }
  else { // Opponent minimizes my score
    memo[i][j] = min(dp(memo, v, i + 1, j, !my_turn), // Opponent picks v[i] if this will minimize MY winnings
                     dp(memo, v, i, j - 1, !my_turn));  // Opponent picks v[j] if this will minimize MY winnings.
  }
```
- TRICK: Implement recursively as it is easier to reason about the implementation & we can "simulate" the game through the `my_turn` variable, that is initially set to `true`, since I start.
- ANS: dp[1][n] (1-indexed)


#  Time complexity
- `O(N^2)`
