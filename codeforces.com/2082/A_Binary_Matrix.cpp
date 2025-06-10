#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::string> a(n + 1);
  std::vector<int> r(n + 1), c(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = '#' + a[i];
    for (int j = 1; j <= m; j++) {
      r[i] ^= a[i][j] == '1';
      c[j] ^= a[i][j] == '1';
    }
  }
  int rcnt = 0, ccnt = 0;
  for (int i = 1; i <= n; i++) {
    rcnt += r[i] == 1;
  }
  for (int i = 1; i <= m; i++) {
    ccnt += c[i] == 1;
  }
  std::cout << std::max(rcnt, ccnt) << '\n';
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