// date: 2024-07-18 11:51:12
// tag: 数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int W = 1e9;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::map<int, int> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    m[a[i]]++;
  }
  int ans = 0;
  for (auto &[k, v] : m) {
    if (!v) continue;
    ans += v * (v - 1) * (v - 2);
    if (k <= 1e6) {
      for (int j = 2; j * j <= k; j++) {
        if (k % j == 0) {
          if (m.count(k * j) && m.count(k / j)) {
            ans += m[k * j] * v * m[k / j];
          }
          if (j * j != k && m.count(j) && m.count(k * k / j)) {
            ans += v * m[j] * m[k * k / j];
          }
        }
      }
      if (k > 1 && m.count(k * k) && m.count(1)) {
        ans += m[k * k] * v * m[1];
      }
    } else {
      for (int j = 2; k * j <= W; j++) {
        if (k % j == 0 && m.count(k * j) && m.count(k / j)) {
          ans += m[k * j] * v * m[k / j];
          // 1e6 <= b < c
        }
      }
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G2.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}