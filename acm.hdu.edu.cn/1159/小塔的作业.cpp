#include <bits/stdc++.h>
#define int long long

void solve() {
  int t, n, m;
  std::cin >> t >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  for (int i = 1; i <= m; i++) {
    t -= a[i];
  }
  if (t < 0) {
    std::cout << -1 << '\n';
    return;
  }
  std::cout << t / 40 << '\n';
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