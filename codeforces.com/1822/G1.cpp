// date: 2024-07-18 09:35:02
// tag: 暴力

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e6;

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
  for (auto [k, v] : m) {
    if (!v) continue;
    ans += v * (v - 1) * (v - 2);
    for (int j = 2; j * j <= k; j++) {
      if (k % (j * j) == 0) {
        ans += v * m[k / j] * m[k / j / j];
      }
    }
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G1.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}