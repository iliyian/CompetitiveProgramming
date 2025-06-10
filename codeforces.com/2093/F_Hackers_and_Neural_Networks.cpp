#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  std::vector<std::vector<std::string>> s(m + 1, std::vector<std::string>(n + 1));
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  // std::vector<std::vector<int>> b(n + 1);
  int mx = 0;
  std::vector<int> b(n + 1), cnt(n + 1);
  for (int i = 1; i <= m; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      std::cin >> s[i][j];
      if (s[i][j] == a[j]) {
        b[j] = 1;
        cnt++;
      }
    }
    mx = std::max(mx, cnt);
  }
  for (int j = 1; j <= n; j++) {
    if (!b[j]) {
      std::cout << -1 << '\n';
      return;
    }
  }
  // std::cerr << mx << '\n';
  std::cout << n + (n - mx) * 2 << '\n';
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