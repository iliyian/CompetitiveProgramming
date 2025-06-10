// date: 2025-03-04 19:18:32
// tag: 比较神奇的均摊复杂度的模拟题，区间合并的一类技巧，不算难

#include <algorithm>
#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::set<int> s;
  std::map<int, std::vector<std::pair<int, int>>> f;
  for (int i = 1; i <= k; i++) {
    int x;
    std::cin >> x;
    int l = 1, r = n, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      if (mid * (mid - 1) / 2 + 1 <= x) l = mid + 1, ans = mid;
      else r = mid - 1;
    }
    int y = x - ans * (ans - 1) / 2;
    // std::cerr << x << ' ' << ans << ' ' << y << '\n';
    f[ans].push_back({y, y});
    s.insert(ans);
  }
  int ans = 0;
  for (int i = *s.rbegin(); i >= 1;) {
    auto &v = f[i];
    std::sort(v.begin(), v.end());
    int px = 0, py = 0;
    for (int j = 0; j < v.size(); j++) {
      auto [x, y] = v[j];
      if (!j) {
        px = x, py = y;
        continue;
      }
      if (x <= py + 1) {
        py = std::max(py, y);
      } else {
        if (px != py) {
          f[i - 1].push_back({px, py - 1});
          s.insert({i - 1});
        }
        ans += py - px + 1;
        // std::cerr << i << ' ' << px << ' ' << py << '\n';
        px = x, py = y;
      }
    }
    if (px) {
      // std::cerr << i << ' ' << px << ' ' << py << '\n';
      if (px != py) {
        f[i - 1].push_back({px, py - 1});
        s.insert({i - 1});
      }
      ans += py - px + 1;
    }
    auto p = s.lower_bound(i);
    if (p == s.begin()) break;
    i = *std::prev(p);
  }
  std::cout << ans << '\n';
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