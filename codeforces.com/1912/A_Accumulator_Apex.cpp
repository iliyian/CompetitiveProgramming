#include <bits/stdc++.h>
#define int long long

void solve() {
  int x, k;
  std::cin >> x >> k;
  std::vector<std::pair<int, int>> a;
  for (int i = 1; i <= k; i++) {
    int l;
    std::cin >> l;
    int mn = 0, mx = 0;
    for (int j = 1; j <= l; j++) {
      int v;
      std::cin >> v;
      if (v > 0) {
        mx++;
      } else if (v < 0) {
        mn--;
      }
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}