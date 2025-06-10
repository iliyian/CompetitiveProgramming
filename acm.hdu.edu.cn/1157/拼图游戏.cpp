#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, k;
  std::cin >> n >> m >> k;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      std::cin >> a[i][j];
    }
  }
  std::vector<int> d(m + 1);
  auto add = [&](int x, int c) -> void {
    for (int i = x; i <= m; i += i & -i) d[i] += c;
  };
  auto query = [&](int x) -> int {
    int ans = 0;
    for (int i = x; i > 0; i -= i & -i) ans += d[i];
    return ans;
  };
  std::vector<int> pos(k + 1, m + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int l = 1, r = m, _ans = -1;
    for (int j = 1; j <= m; j++) {
      if (pos[a[i][j]] > j) {
        if (pos[a[i][j]] != m + 1) {
          add(pos[a[i][j]], -1);
        }
        pos[a[i][j]] = j;
        add(j, 1);
      }
    }
    while (l <= r) {
      int mid = (l + r) / 2;
      if (query(mid) >= k) r = mid - 1, _ans = mid;
      else l = mid + 1;
    }
    if (_ans != -1) {
      // std::cerr << i << ' ' << m - _ans + 1 << '\n';
      ans += m - _ans + 1;
    }
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