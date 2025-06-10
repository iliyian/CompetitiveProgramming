// date: 2025-03-19 10:11:22
// tag: 又是疑似很adhoc的题，基于全-1，1序列的可构造的子段和问题，也就是最小和最大弄个闭区间，然后处理一下中间的，基于前后缀mnmx，就很怪

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int i = 1;
  while (i <= n && std::abs(a[i]) == 1) i++;
  std::vector<int> sum(n + 2);
  int mx1 = 0, mn1 = 0, mx2 = 0, mn2 = 0;
  for (int j = i - 1; j >= 1; j--) {
    sum[j] = sum[j + 1] + a[j];
    mx1 = std::max(mx1, sum[j]);
    mn1 = std::min(mn1, sum[j]);
  }
  for (int j = i + 1; j <= n; j++) {
    sum[j] = sum[j - 1] + a[j];
    mx2 = std::max(mx2, sum[j]);
    mn2 = std::min(mn2, sum[j]);
  }
  int l = mn1 + mn2 + a[i], r = mx1 + mx2 + a[i];
  // std::cerr << l << ' ' << r << '\n';
  std::set<int> ans;
  for (int j = l; j <= r; j++) ans.insert(j);
  std::vector<int> f(n + 2), g(n + 2);
  for (int j = i - 1; j >= 1; j--) {
    f[j] = std::max(f[j + 1] + a[j], a[j]);
  }
  for (int j = i + 1; j <= n; j++) {
    f[j] = std::max(f[j - 1] + a[j], a[j]);
  }
  for (int j = i - 1; j >= 1; j--) {
    g[j] = std::min(g[j + 1] + a[j], a[j]);
  }
  for (int j = i + 1; j <= n; j++) {
    g[j] = std::min(g[j - 1] + a[j], a[j]);
  }
  {
    int mn1 = 0, mx1 = 0, mx2 = 0, mn2 = 0;
    for (int j = 1; j <= n; j++) {
      if (j < i) {
        mn1 = std::min(mn1, g[j]);
        mx1 = std::max(mx1, f[j]);
      } else if (j > i) {
        mn2 = std::min(mn2, g[j]);
        mx2 = std::max(mx2, f[j]);
      }
      // std::cerr << mn1 << ' ' << mx1 << ' ' << i << '\n';
    }
    for (int j = mn1; j <= mx1; j++) ans.insert(j);
    for (int j = mn2; j <= mx2; j++) ans.insert(j);
  }
  ans.insert(0);
  std::cout << ans.size() << '\n';
  for (int i : ans) {
    std::cout << i << ' ';
  }
  std::cout << '\n';
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