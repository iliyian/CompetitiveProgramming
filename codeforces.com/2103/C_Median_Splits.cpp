// date: 2025-04-24 00:28:10
// tag: 大胆假设，小心求证。独立过题的感觉确实很爽。主要是要从数据小的地方入手，这里3就是突破口。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] = (a[i] > k);
  }
  for (int t = 0; t < 2; t++) {
    std::vector<int> f(n + 1);
    int sum = 0, cnt = 0, mx = LLONG_MIN, fst = 0;
    for (int i = 1; i <= n; i++) {
      sum += a[i];
      cnt++;
      f[i] = 2 * sum - cnt;
      if (mx >= f[i] && i <= n - 1) {
        std::cout << "YES\n";
        // std::cerr << i << '\n';
        return;
      }
      if (sum <= cnt / 2) {
        if (!fst) fst = i;
        mx = std::max(mx, f[i]);
      }
    }
    if (fst) {
      sum = 0, cnt = 0;
      for (int i = n; i > fst; i--) {
        sum += a[i], cnt++;
        if (sum <= cnt / 2) {
          std::cout << "YES\n";
          return;
        }
      }
    }
    std::reverse(a.begin() + 1, a.end());
  }
  std::cout << "NO\n";
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