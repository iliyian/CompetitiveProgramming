// date: 2025-04-29 09:49:21
// tag: 吃观察的题

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, T;
  std::cin >> n >> m >> T;
  std::vector<int> a(n + 1), b(m + 1), start(n + 1), s(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
    start[b[i]] = 1;
  }
  int ans = 0;
  auto work = [&]() {
    int lst = -1;
    for (int i = 1; i <= n; i++) {
      s[i] = s[i - 1] + a[i];
      if (start[i]) {
        lst = i;
      }
      if (lst != -1) {
        if (s[i - 1] - s[lst - 1] <= T) {
          ans = std::max(ans, (T - (s[i - 1] - s[lst - 1])) / a[i] + i - lst);
        }
      }
    }
  };
  work();
  std::reverse(a.begin() + 1, a.end());
  std::reverse(start.begin() + 1, start.end());
  work();
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