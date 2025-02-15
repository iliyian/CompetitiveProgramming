

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m, q;
  std::cin >> n >> m >> q;
  std::vector<int> a(n + 1);
  std::vector<int> vis(n + 1), b(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    std::cin >> b[i];
  }
  int i = 1, j = 1;
  while (i <= n && j <= m) {
    while (j <= m && vis[b[j]]) j++;
    if (j > m) break;
    vis[b[j]] = 1;
    if (j <= m && a[i] == b[j]) {
      i++, j++;
    } else {
      std::cout << "TIDAK\n";
      return;
    }
  }
  std::cout << "YA\n";
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