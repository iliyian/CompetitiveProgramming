#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1), b(m + 1);
  std::string s, t;
  std::cin >> s >> t;
  for (int i = 1; i <= n; i++) {
    a[i] = s[i - 1] - '0';
  }
  for (int i = 1; i <= m; i++) {
    b[i] = t[i - 1] - '0';
  }
  int p = 1;
  while (p <= m && b[p] == 0) p++;
  int ans = 0;
  // std::cerr << p << '\n';
  for (int i = p; i + m - 1 <= n; i++) {
    if (a[i] == 1) {
      ans++;
      for (int j = p; j <= m; j++) {
        a[i + j - p] ^= b[j];
      }
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << b[i] << ' ';
  // }
  // std::cout << '\n';
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      std::cout << -1 << '\n';
      return;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
	freopen("d.in", "r", stdin);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
