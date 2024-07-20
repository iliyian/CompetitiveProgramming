// date: 2024-07-06 20:02:17
// tag: 边界Mx应为-inf

#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int ans = inf;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  sort(a.begin() + 1, a.end());

  std::vector<int> mx(n + 2);
  mx[n + 1] = -inf;
  for (int i = n; i >= 1; i--) {
    mx[i] = std::max(mx[i + 1], a[i].second);
  }

  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    auto [x, y] = a[i];
    auto p = i + 1;

    int mn = inf, Mx = mx[p];

    if (!s.empty()) {
      auto p = s.lower_bound(x);
      if (p != s.end()) {
        mn = std::min(mn, abs(x - *p));
      }
      if (p != s.begin()) {
        mn = std::min(mn, abs(x - *prev(p)));
      }
    }

    if (Mx >= x) {
      ans = std::min(ans, Mx - x);
    } else {
      ans = std::min({ans, mn, x - Mx});
    }

    s.insert(y);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}