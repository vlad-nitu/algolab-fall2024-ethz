///4
#include <bits/stdc++.h>
using namespace std; 

using vec_t = vector<int>;
using mat_t = vector<vec_t>; 
using graph_t = mat_t;

int solve_dp(mat_t &dp, const graph_t &G, int n, int u, bool turn) {

  if (dp[u][turn] != -1)
    return dp[u][turn];
  
  if (!turn) { // H min red & H min black
    dp[u][turn] = INT_MAX;
    for (auto &v: G[u]) {
      dp[u][turn] = min(dp[u][turn], solve_dp(dp, G, n, v, !turn) + 1); 
    }
  }
  else { // M max red & H max black
    for (auto &v: G[u]) {
      dp[u][turn] = max(dp[u][turn], solve_dp(dp, G, n, v, !turn) + 1); 
    }
  }
  
  return dp[u][turn]; 

}

int solve_red(const graph_t &G, int n, int start_r) {
  mat_t dp(n + 1, vec_t(2, -1)); 
  dp[n][0] = dp[n][1] = 0; // 0 -> H, 1 -> M
  // H min for red, M max for red
  solve_dp(dp, G, n, start_r, false); 
  return dp[start_r][0];
}


int solve_black(const graph_t &G, int n, int start_b) {
  mat_t dp(n + 1, vec_t(2, -1)); 
  // dp[u][turn] = min number of nodes we have to visit to reach `n`, starting from `u`.
  // turn = 0 minimizes, turn = 1 maximizes
  dp[n][0] = dp[n][1] = 0; // 0 -> M, 1 -> H
  solve_dp(dp, G, n, start_b, false); 
  return dp[start_b][0];
}

void solve() {
  int n, m; cin >> n >> m;
  int start_r, start_b; cin >> start_r >> start_b;
  graph_t G(n); 
  for (int i = 0; i < m; ++i) {
    int u, v; cin >> u >> v; 
    G[u].push_back(v); 
  }
  
  // Base case
  int red_cnt = solve_red(G, n, start_r); 
  int black_cnt = solve_black(G, n, start_b); 
  
  if (red_cnt < black_cnt || (red_cnt == black_cnt && red_cnt % 2 == 1)) {
    std::cout << 0 << '\n';
  }
  else {
    std::cout << 1 << '\n'; 
  }
    
}

int main() {
  std::ios_base::sync_with_stdio(false);
  int t; cin >> t;
  while (t--)
    solve();
}
