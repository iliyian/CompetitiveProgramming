// date: 2024-07-24 09:18:10
// tag: 数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), c(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
  }
  std::vector<int> id(n + 1);
  std::iota(id.begin() + 1, id.end(), 1);
  std::sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
    return a[x] < a[y];
  });

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, std::min(c[i], m / a[i]) * a[i]);
  }

  for (int i = 1; i < n; i++) {
    if (a[id[i + 1]] != a[id[i]] + 1) continue;
    int k1 = std::min(c[id[i]], m / a[id[i]]);
    int r = m - k1 * a[id[i]];
    int k2 = std::min(c[id[i + 1]], r / a[id[i + 1]]);
    int t = std::min({k1, r - k2 * a[id[i + 1]], c[id[i + 1]] - k2});
    // 多重限制
    int mx = (k1 - t) * a[id[i]] + (k2 + t) * a[id[i + 1]];
    ans = std::max(ans, mx);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B2.in", "r", stdin);
  freopen("B2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}