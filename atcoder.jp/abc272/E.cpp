#include <bits/stdc++.h>
#define int long long

signed main() {
  // freopen("E.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::vector<std::set<int>> ans(m + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] > n) continue;
    for (int j = std::max(1ll, (-a[i] + i - 1) / i); j <= m; j++) {
      if (a[i] + j * i > n) break;
      ans[j].insert(a[i] + j * i);
      assert(a[i] + j * i >= 0);
      assert(a[i] + j * i <= n);
    }
  }
  for (int i = 1; i <= m; i++) {
    int mex = 0;
    for (int j : ans[i]) {
      if (j == mex) mex++;
      else break;
    }
    std::cout << mex << '\n';
  }
}