#include <iostream>
using namespace std; 
int t, n, x;
int main() {
  cin >> t;
  while (t --) {
      long s = 0;
      cin >> n;
      while (n --) {
        cin >> x; 
        s += x;
      }
      cout << s << '\n';
  }
    
}
