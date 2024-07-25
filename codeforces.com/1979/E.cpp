// date: 2024-07-25 12:31:08
// tag: 曼哈顿距离转切比雪夫距离，计算几何

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
// using namespace std;

void solve() {
  int n, d;
  std::cin >> n >> d;
  std::vector<std::array<int, 3>> a;
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    a.push_back({x + y, x - y, i + 1});
  }
  for (int t = 0; t < 2; t++) {
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      auto [x1, y1, id1] = a[i];
      auto j = std::lower_bound(a.begin(), a.end(), std::array<int, 3>{x1, y1 + d, 0});
      if (j == a.end() || (*j)[0] != x1 || (*j)[1] != y1 + d) {
        continue;
      }
      auto [x2, y2, id2] = *j;

      int x3 = x1 - d;
      auto k = std::lower_bound(a.begin(), a.end(), std::array<int, 3>{x3, y1, 0});
      if (k != a.end() && (*k)[0] == x3 && (*k)[1] <= y2) {
        std::cout << id1 << ' ' << id2 << ' ' << (*k)[2] << '\n';
        // std::cout << std::format("{} {} {} {} {} {} 1 {} {}\n", x1, y1, x2, y2, (*k)[0], (*k)[1], t, d);
        return;
      }

      x3 = x1 + d;
      k = std::lower_bound(a.begin(), a.end(), std::array<int, 3>{x3, y1, 0});
      if (k != a.end() && (*k)[0] == x3 && (*k)[1] <= y2) {
        std::cout << id1 << ' ' << id2 << ' ' << (*k)[2] << '\n';
        // std::cout << std::format("{} {} {} {} {} {} 2 {} {}\n", x1, y1, x2, y2, (*k)[0], (*k)[1], t, d);
        return;
      }
    }
    for (auto &[x, y, id] : a) {
      std::swap(x, y);
    }
  }
  std::cout << "0 0 0\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}