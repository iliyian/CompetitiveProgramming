#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n), b(n);
  for (auto &i : a) std::cin >> i;
  for (auto &i : b) std::cin >> i;
  std::set<std::vector<int>> s;
  auto dfs = [&](auto self, int u) {
    if (s.count(a)) return;
    s.insert(a);
    if (a == b) {
      std::cout << "YES\b";
    }
    auto temp = a;
    for (int i = 0; i < k; i++) {
      int t = a[0];
      for (int j = 0; j < k; j++) {
        a[j] = a[j + 1];
      }
      a[k] = t;
      temp = a;
      self(self, u);
      a = temp;
    }
  };
  dfs(dfs, 1);
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