#include <bits/stdc++.h>
#define int long long

void solve() {
  int q, x;
  std::cin >> q >> x;
  std::set<std::pair<int, int>> s;
  std::vector<int> cnt(x);
  for (int i = 0; i < x; i++) {
    s.insert({0, i});
  }
  while (q--) {
    int y;
    std::cin >> y;
    y %= x;
    s.erase({cnt[y], y});
    cnt[y]++;
    s.insert({cnt[y], y});
    auto [v, k] = *s.begin();
    std::cout << v * x + k << '\n';
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