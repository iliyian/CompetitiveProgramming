#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> ans(n + 1);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (x == 1) {
      std::cout << cur++ << ' ';
    } else {
      std::cout << 
    }
  }
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