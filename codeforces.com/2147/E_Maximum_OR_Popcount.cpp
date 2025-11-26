#include <bits/stdc++.h>
#define int long long

auto calc(std::vector<int> &v) {
  return std::accumulate(v.begin(), v.end(), 0ll, std::bit_or());
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<int> a(n + 1), cnt(41);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto s = calc(a);
  std::vector<std::pair<int, int>> ans;
  ans.push_back({0, __builtin_popcountll(s)});
  for (int i = 0; i <= 40; i++) {
    if (s >> i & 1 ^ 1) {
      auto b = a;
      auto ss = calc(b);
      int now = 0;
      for (int j = i; j >= 0; j--) {
        if (ss >> j & 1 ^ 1) {
          int S = (1ll << j) - 1;
          auto mx = std::max_element(b.begin(), b.end(), [&](auto x, auto y) {
            return x & S;
          });
          now += (1ll << j) - ;
        }
      }
    }
  }
  while (q--) {
    int b;
    std::cin >> b;
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