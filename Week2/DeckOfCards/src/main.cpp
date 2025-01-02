///1
#include <bits/stdc++.h>
using namespace std;


void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> v(n, 0);
    vector<int> pre(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i)
        pre[i] = (i > 0 ? (pre[i-1] + v[i]) : v[i]);

  
  int ii = -1, jj = -1;
  int ans = INT_MAX;
  int i = 0, j = 0; 
  int sw = 0; // sliding window = s[i:j]
  // [i, j]
  while (i < n && j < n) {
    if (i > j) {
      j = i;
    }

    sw = (i > 0 ? (pre[j] - pre[i - 1]) : pre[j]); 

    
    if (abs(k-sw) < ans) {
      ans = abs(k - sw);
      ii = i; jj = j; 
    }
    
    if (sw <= k)
      j ++;
    else
      i ++; 
    
  }
  std::cout << ii << ' ' << jj << '\n';
  
}

int main() {
    std::ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t --)
        solve();
}
