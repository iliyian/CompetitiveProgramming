#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> x(n + 1), y(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::vector<std::pair<int, int>> k;
  std::vector<std::pair<int, int>> v;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      v.push_back({x[j] + x[i], y[j] + y[i]});
      int dx = x[j] - x[i], dy = y[j] - y[i];
      if (dx == 0) {
        k.push_back({1, 0});
      } else if (dy == 0) {
        k.push_back({0, 1});
      } else {
        if (dx < 0) {
          dx *= -1, dy *= -1;
        }
        int g = std::gcd(std::abs(dx), std::abs(dy));
        k.push_back({dy / g, dx / g});
      }
    }
  }
  std::ranges::sort(k);
  int cnt = 0, ans = 0;
  std::pair<int, int> prv = {0, 0};
  for (auto v : k) {
    // std::cerr << v.first << ' ' << v.second << '\n';
    if (v != prv) {
      ans += cnt * (cnt - 1) / 2;
      cnt = 1;
      prv = v;
    } else {
      cnt++;
    }
  }
  ans += cnt * (cnt - 1) / 2;
  cnt = 0;
  std::ranges::sort(v);
  prv = {LLONG_MIN, LLONG_MIN};
  for (auto v : v) {
    if (v != prv)  {
      ans -= cnt * (cnt - 1) / 2;
      cnt = 1;
      prv = v;
    } else {
      cnt++;
    }
  }
  ans -= cnt * (cnt - 1) / 2;
  std::cout << ans << '\n';
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