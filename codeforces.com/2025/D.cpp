// date: 2024-12-02 14:48:19
// tag: dp中常见的利用变量总和固定从而降低维数的做法，dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  std::vector<int> f(m + 1), d(m + 2);
  int cur = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] == 0) {
      cur++;
      for (int j = 0; j <= cur; j++) {
        d[j] += (j ? d[j - 1] : 0);
        f[j] += d[j];
      }
      for (int j = 0; j <= cur; j++) {
        d[j] = 0;
      }
      for (int j = cur; j >= 1; j--) {
        f[j] = std::max(f[j], f[j - 1]);
      }
    } else if (a[i] > 0) {
      if (cur < a[i]) continue;
      d[a[i]]++, d[cur + 1]--;
    } else {
      if (cur + a[i] < 0) continue;
      d[0]++, d[cur + a[i] + 1]--;
    }
  }
  int ans = INT_MIN;
  for (int j = 0; j <= cur; j++) {
    d[j] += (j ? d[j - 1] : 0);
    f[j] += d[j];
  }
  for (int j = cur; j >= 1; j--) {
    f[j] = std::max(f[j], f[j - 1]);
  }
  for (int i = 0; i <= m; i++) {
    ans = std::max(ans, f[i]);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}