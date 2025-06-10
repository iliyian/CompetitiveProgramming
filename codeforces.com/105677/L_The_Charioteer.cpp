#include <bits/stdc++.h>
#define int long long

int ask(char op) {
  std::cout << "? " << op << std::endl;
  int x;
  std::cin >> x;
  return x;
}

void solve() {
  int x = ask('F'), y = ask('F'), z = ask('F');
  
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}