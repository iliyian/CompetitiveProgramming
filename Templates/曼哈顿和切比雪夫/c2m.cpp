// date: 2024-07-25 13:25:26
// tag: 切比雪夫距离转曼哈顿距离

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int n;
  std::cin >> n;

  std::vector<std::pair<int, int>> a, b;

  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    if ((x + y) % 2) {
      b.push_back({(x + y + 1) / 2, (x - y - 1) / 2});
    } else {
      a.push_back({(x + y) / 2, (x - y) / 2});
    }
  }
  int ans = 0;
  for (int t = 0; t < 2; t++) {
    std::sort(a.begin(), a.end());
    int prv = 0;
    for (int i = 0; i < a.size(); i++) {
      auto [x, y] = a[i];
      ans += x * i - prv;
      prv += x;
    }
    for (auto &[x, y] : a) {
      std::swap(x, y);
    }
  }

  for (int t = 0; t < 2; t++) {
    std::sort(b.begin(), b.end());
    int prv = 0;
    for (int i = 0; i < b.size(); i++) {
      auto [x, y] = b[i];
      ans += x * i - prv;
      prv += x;
    }
    for (auto &[x, y] : b) {
      std::swap(x, y);
    }
  }

  std::cout << ans << '\n';

  return 0;
}