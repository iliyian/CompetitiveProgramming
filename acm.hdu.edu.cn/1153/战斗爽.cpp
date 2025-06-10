#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, u, k, hq;
  std::cin >> n >> u >> k >> hq;
  std::vector<std::array<int, 3>> a(n + 1);
  std::vector<int> mx(n + 2);
  std::vector<int> t(62);
  t[1] = u;
  int cu = u / 2;
  for (int i = 2; i <= 61; i++) {
    t[i] = t[i - 1] + cu;
    // cu /= 2;
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i][1] >> a[i][0];
    a[i][2] = i;
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = n; i >= 1; i--) {
    mx[i] = std::max(mx[i + 1], a[i][1]);
  }
  for (int i = 1; i <= n; i++) {
    auto [h, atk, id] = a[i];
    auto th = (hq + mx[i] - 1) / mx[i];
    auto tg = std::lower_bound(t.begin() + 1, t.end(), h) - t.begin();
    // std::cerr << hq << '\n';
    if (th < tg || tg > k) {
      std::cout << i - 1 << '\n';
      return;
    }
    hq -= (tg - 1) * mx[i] + mx[i + 1];
    if (hq <= 0) {
      std::cout << i << '\n';
      return;
    }
  }
  std::cout << n << '\n';
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