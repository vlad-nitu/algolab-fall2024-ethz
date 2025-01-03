///1
#include <bits/stdc++.h>
using namespace std;

using vec_t = vector<int>;
using mat_2d_t = vector<vec_t>; 
using mat_3d_t = vector<mat_2d_t>; 

int dp(mat_3d_t &memo, const vec_t &v,
       int n, int m, int cnt, int k, int i, int j) {
         
      bool turn = (cnt == k); // 1: if my_turn, 0: any other passanger, other than p_k, turn
      if (memo[turn][i][j] != -1)
        return memo[turn][i][j];
      if (i == j) {
        if (turn)
          memo[turn][i][j] = v[i];
        else
          memo[turn][i][j] = 0;
          
        return memo[turn][i][j];
      }
      
      if (!turn) { // Passengers other than p_k try to minimise his winnings
        memo[turn][i][j] = min(dp(memo, v, n, m, (cnt + 1) % m, k, i + 1, j), // p_turn picks v[i]
                               dp(memo, v, n, m, (cnt + 1) % m, k, i, j - 1)); // p_turn picks v[j]
      }
      else { // p_k tries to maximize his winning
        memo[turn][i][j] = max(v[i] + dp(memo, v, n, m, (cnt + 1) % m, k, i + 1, j), // p_k picks v[i] -> add v[i] to final score
                               v[j] + dp(memo, v, n, m, (cnt + 1) % m, k, i, j - 1)); // p_k picks v[j] -> add v[j] to final score
      }
    
      return memo[turn][i][j];
  
}

void solve() { 
  int n, m, k; cin >> n >> m >> k; 
  vec_t v(n + 1, 0);
  for (int i = 1; i <= n; ++i)
    cin >> v[i];
  
  // memo[turn][i][j] = largest winning that passanger p_k can collect when the passengers are still to pick from segment [i:j]
  mat_3d_t memo(2, mat_2d_t(n + 1, vec_t(n + 1, -1)));
  std::cout << dp(memo, v, n, m, 0, k, 1, n) << '\n'; 
  
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve(); 
}
