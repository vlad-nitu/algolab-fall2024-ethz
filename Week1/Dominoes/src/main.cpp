#include <iostream>
using namespace std;

void solve() {
  int n; cin >> n;
  int x; cin >> x; 
  int fall_id = x;
  bool still_falling = true; 
  int ans = 1;
  for (int i = 2; i <= n; ++i) {
    cin >> x; 
    if (!still_falling)
      continue; // just consume input;
    if (fall_id < i) {
      still_falling = false;
      continue;
    }
      
    fall_id = std::max(fall_id, i + x - 1); 
    ans = i; 
  }
  
  std::cout << ans << '\n';
}

int main() {
  int t; cin >> t;
  while (t --)
    solve();
}
