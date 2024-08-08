// date: 2024-08-03 13:46:01
// tag: 构造，几何

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;
  std::vector<std::pair<int, int>> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i].first >> a[i].second;
  }
  while (true) {
    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
      if ((a[i].first + a[i].second) % 2 == 0) {
        ans.push_back(i);
      }
    }
    bool f = false;
    if (ans.size() != n && ans.size() != 0) {
      std::cout << ans.size() << '\n';
      for (auto i : ans) {
        std::cout << i << ' ';
      }
      std::cout << '\n';
      return 0;
    } else if (ans.size() == 0) {
      f = true;
    }
    for (int i = 1; i <= n; i++) {
      auto &[x, y] = a[i];
      int xx = (x + y + f) / 2, yy = (x - y - f) / 2;
      x = xx, y = yy;
    }
  }

  return 0;
}