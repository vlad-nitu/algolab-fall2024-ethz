///2
#include <bits/stdc++.h>
using namespace std;
using vec_t = std::vector<int>; 
using mat_t = std::vector<vec_t>; 

int dp(mat_t &memo, const vec_t &v, int i , int j, bool my_turn) {
  if (memo[i][j] != -1)
    return memo[i][j];
  
  if (i == j) { // Base case
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
  
  return memo[i][j];

}

void solve() { 
  int n; cin >> n;
  vec_t v(n + 1, 0); // 1-idx
  
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
    
  // memo[i][j] = max. amount of money I win when we still have to play [i:j] segment of coins, and I start. 
  mat_t memo(n + 1, vec_t(n + 1, -1)); 
  cout << dp(memo, v, 1, n, true) << '\n'; 
  
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve();
}
