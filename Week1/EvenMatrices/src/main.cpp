
#include <bits/stdc++.h> 
using namespace std; 

using vec_t = std::vector<int>;
using mat_t = std::vector<vec_t>;

mat_t precalculate_pref_sum_col(const mat_t &v) {
  int n = v.size();
  mat_t pref_sum_col(n, vec_t(n, 0));
  for (int j = 0; j < n; ++j) {
    for (int i = 0; i < n; ++i) {
      if (i == 0)
        pref_sum_col[j][i] = v[i][j];
      else
        pref_sum_col[j][i] = v[i][j] + pref_sum_col[j][i - 1];
    }
  }
  return pref_sum_col;
}

vec_t reduce_between_rows_to_vec(const mat_t& pref_sum_col, const mat_t& v, int i1, int i2) {
  int n = v.size();
  vec_t a(n, 0); // v(n)
  for (int j = 0; j < n; ++j) {
    if (i1 >= 1)
      a[j] = pref_sum_col[j][i2] - pref_sum_col[j][i1 - 1]; 
    else
      a[j] = pref_sum_col[j][i2]; 
  }
  
  return a;
}

int solve_even_pairs(const vec_t &v){ // My solution, copied from here: https://expert.ethz.ch/ide2/zXr35a2p5W7ByToBv?fileKey=pNm5vscMvLDJd9nvs
  int n = v.size();
  int ans = 0, pre_sum = 0;
  int evens_before = 1, odds_before = 0; // There is `1` evens_before, which is {}, to allow counting s[0:i]; where j+1 = 0 => j = -1;
  for (int i = 0; i < n; ++i) {
    int x = v[i];  
    pre_sum += x;
    if (pre_sum % 2 == 0) { // s[0:i] even
        ans += evens_before; // match s[0:i] with all s[0:j], j < i s.t: s[0:j] is even, so that s[j+1:i] = s[0:i] - s[0:j] is (even - even) even
        evens_before ++; 
    }
    else { // s[0:j] odd
        ans += odds_before; // match s[0:i] with all s[0:j], j < i s.t: s[0:j] is odd, so that s[j+1:i] = s[0:i] - s[0:j] is (odd - odd) even 
        odds_before ++; 
    }
  }
  return ans;
}

void solve() {
  int n; cin >> n;
  mat_t v(n, vec_t(n, 0)); 
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> v[i][j];
  
  mat_t pref_sum_col = precalculate_pref_sum_col(v); // pref_sum_col[j][i] = sum of all elements on col 'j' between rows '0' to 'i', inclusive
  
  int ans = 0;
  for (int i1 = 0; i1 < n; ++i1)
    for (int i2 = i1; i2 < n; ++i2) {
      vec_t even_pairs_in = reduce_between_rows_to_vec(pref_sum_col, v, i1, i2); 
      ans += solve_even_pairs(even_pairs_in);
    }
  
  std::cout << ans << '\n';
}

int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t --)
    solve(); 
  return 0;
}
