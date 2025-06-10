// date: 2025-03-31 17:39:51
// tag: 构造

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), pos(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    pos[a[i]] = i;
  }
  std::vector<std::pair<int, int>> ans;
  for (int i = 1; i <= n; i++) {
    std::vector<int> front, rear;
    for (int j = 1; j < i; j++) {
      if (pos[j] < pos[i]) {
        front.push_back(pos[j]);
      } else {
        rear.push_back(pos[j]);
      }
    }
    std::sort(rear.begin(), rear.end());
    for (auto j : rear | std::views::reverse) {
      // std::cout << i << ' ' << a[j] << '\n';
      ans.push_back({i, a[j]});
    }
    std::sort(front.begin(), front.end());
    for (auto j : front | std::views::reverse) {
      // std::cout << i << ' ' << a[j] << '\n';
      ans.push_back({i, a[j]});
    }
    for (auto j : front) {
      // std::cout << a[j] << ' ' << i << '\n';
      ans.push_back({a[j], i});
    }
  }
  std::cout << ans.size() << '\n';
  for (auto [x, y] : ans) {
    std::cout << x << ' ' << y << "\n";
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