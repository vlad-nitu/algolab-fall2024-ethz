///1
#include <iostream>
using namespace std;

void solve() {
  int n; cin >> n;
  int ans = 0, pre_sum = 0;
  int evens_before = 1, odds_before = 0; // There is `1` evens_before, which is {}, to allow counting s[0:i]; where j+1 = 0 => j = -1;
  for (int i = 0; i < n; ++i) {
    int x; cin >> x; 
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
  
  std::cout << ans << '\n'; 
}

int main() {
  
  std::ios_base::sync_with_stdio(false); 
  int t; cin >> t;
  while (t --)
    solve();
    
}
