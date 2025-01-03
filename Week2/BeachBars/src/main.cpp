///3
#include <bits/stdc++.h>
using namespace std;
 
 
using vec_t = std::vector<int>; 
using set_t = std::set<int>; 
 
void solve() {
  int n; cin >> n;
  vec_t x(n, 0); 
  for (auto &val: x)
    cin >> val;
  
  sort(x.begin(), x.end());
  
  
  int i = 0, j = 0; // [i, j]
  set_t opt_locs{}; 
  int max_num_parasols = -1; 
  int min_dist = INT_MAX;
  
  int curr_num_parasols = 0;
  int curr_min_dist = -1;
  
  while (i < n && j < n) {
    if (i > j)
      j = i;

    
    int diff = x[j] - x[i];
    curr_num_parasols = j - i + 1;

    

    if (diff <= 200) {
    
      
      vec_t cands{}; 
      if (diff % 2 == 0)
      {
        cands.push_back(x[i] + diff / 2); 
        curr_min_dist = diff/2;
      }
      else {
        cands.push_back(x[i] + diff / 2);
        cands.push_back(x[i] + diff/ 2 + 1);
        curr_min_dist = diff/2 + 1;
      }
      
      
      if (curr_num_parasols > max_num_parasols) {
        max_num_parasols = curr_num_parasols; 
        opt_locs.clear();
        for (int i = 0; i < (int)cands.size(); ++i)
          opt_locs.insert(cands[i]); 
        min_dist = curr_min_dist;
      }
      else if (curr_num_parasols == max_num_parasols) {
        
        if (curr_min_dist < min_dist) {
          max_num_parasols = curr_num_parasols; 
          opt_locs.clear();
          for (int i = 0; i < (int)cands.size(); ++i)
            opt_locs.insert(cands[i]); 
          min_dist = curr_min_dist;
        }
        else if (curr_min_dist == min_dist) {
          for (int i = 0; i < (int)cands.size(); ++i)
            opt_locs.insert(cands[i]); 
        }
      }
    
    
      j ++; 
    }
    else {
      i ++; 
    }
    
  }
  
  std::cout <<  max_num_parasols << ' ' << min_dist << '\n'; 
  for (auto &loc: opt_locs)
    std::cout << loc << ' ';
  std::cout << '\n'; 
  
}
 
int main() {
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t--)
    solve();
}
