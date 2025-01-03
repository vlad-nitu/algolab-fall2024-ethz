///1
#include <bits/stdc++.h>
using namespace std; 
using vec_t = std::vector<int>; 
using mat_t = std::vector<vec_t>; 


bool is_feasible(const mat_t &dp, int m, int n) {
  bool feasible = true;
  for (int i = 1; i <= m && feasible; ++i) {
    bool OK = false;
    for (int j = 1; j <= n && !OK; ++j)
      if (dp[i][j] != -1) 
        OK = true;
    if (!OK) // exists a line full of -1s
      feasible = false; 
  }
  return feasible;
}

void solve() { 
  // n - defenders, m - attackers; k - streng of attacker
  int n, m, k; cin >> n >> m >> k; 
  vec_t def(n + 1, 0), pre_def(n + 1, 0);
  for (int i = 1; i <= n; ++i) {
    cin >> def[i];
    pre_def[i] = pre_def[i - 1] + def[i]; 
  }
  
  vec_t pred(n + 1, -1); // pref[j] = predecesor of defender `j`, such that: sum[pref[j] + 1 : j] == k for Sliding Window
  int i = 1, j = 1; // [i, j]
  while (i <= n && j <= n) {
    if (i > j)
      j = i;
    
    int S = pre_def[j] - pre_def[i - 1];  
    if (S == k) { // Mark pred[j] & shrink window
      pred[j] = i - 1;
      i ++;
    }
    else if (S < k) { // Expand SW
      j ++;
    }
    else { // S > k => shrink window
      i ++;
    }
  }
  
  mat_t dp(m + 1, vec_t(n + 1, -1));
  // Base case: i = 0: No attacker attacking can obtain no score
  for (int j = 0; j <= n; ++j)
    dp[0][j] = 0;max 
  
  // Recurrence eq.
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
  
  bool feasible = is_feasible(dp, m, n); 
  if (feasible) {
    std::cout << dp[m][n] << '\n'; 
  }
  else { // Not all attackers attack a defender.
    std::cout << "fail\n";      
  }
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while (t--)
    solve();
}
