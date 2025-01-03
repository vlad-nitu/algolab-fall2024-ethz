# Topics
- DP

# Idea: 
- The initial game (proposed in the task) looks like this: 
```
H: R, B, R, B, ...
M: B, R, B, R, ...
Where H = Holmes, M = Moriarty, R = red meeple, B = black meeple
```
- Holmes wants to get the red meeple as fast as possible to `n=target` meeple, and the black meeple as slow as possible there. The contrary holds for Moriarty: who wants to get the black meeple as fast as possible to `target`, and the red one as slow as possible.
- Split the game into 2 individual games: one with the red meeple, and one with the black meeple.  The game thus becomes:
```
R: H, M, H, M, ...
B: M, H, M, H, ...
Where H = Holmes, M = Moriarty, R = red meeple, B = black meeple
```
- The first player in each of the Red and Black games minimizes the moves, while the opponent maximizes the moves => even turns: minimize, odd turns: maximize. 
- Solve using recursion, and keep track of whether the move is odd or even w/ a `bool turn = false` depicting even turns, and `bool turn = true` depicting odd turns.
- Let `dp[u][turn] = min number of nodes we have to visit to reach n, starting from u; turn = 0: player that minimizes, turn = 1: player that maximizes`
```
// Base case: reaching `n` from `n` takes 0 moves
dp[n][0] = dp[n][1] = 0;
// Rec. relationship/eq
dp[u][turn] = min_v(dp[v][!turn]) + 1), if turn == 0
dp[u][turn] = max_v(dp[v][!turn]) + 1), if turn == 1
```
- ANS: 2 cases
1. Basic case: red_cnt = dp[start_r][0] < black_cnt = dp[start_b][0]: Red meeple reaches `n` faster than Black meeple => "0" = Holmes
2. Edge case: red_cnt == black_cnt && red_cnt % 2 == 1: Red meeple reaches `n` in the same number of moves as than Black meeple, but the number of moves of both was odd. Since Holmes takes the first move => "0" = Holmes reaches faster.
3. Else: "1" -> Moriarty


# Time complexity:
- `O(N)`

