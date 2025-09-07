#include <bits/stdc++.h>
#define int long long

void solve() {
  int id, m, k, n;
  std::cin >> id >> m >> k >> n;
  std::vector<int> ans(m);
  for (int i = 0; i < m; i++) {
    bool f = false;
    for (int j = 0; j < k; j++) {
      std::vector<int> v(n * n);
      int cnt = 0;
      for (int k = 0; k < n * n; k++) {
        std::cin >> v[k];
        for (int s = 0; s < k; s++) {
          cnt += v[s] > v[k];
        }
      }
      if (cnt % 2) {
        f = true;
      }
    }
    if (f) {
      ans[i] = 1;
    }
  }
  for (int i = 0; i < m; i++) {
    std::cout << ans[i];
  }
  std::cout << '\n';
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