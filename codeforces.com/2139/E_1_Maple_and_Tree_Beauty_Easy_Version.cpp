// date: 2025-09-09 18:57:10
// tag: 他妈的凭什么这么简单，随便转换一下是吧，跟D一样

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x;
    std::cin >> x;
    g[x].push_back(i);
  }
  std::vector<int> a(n + 1), dep(n + 1);
  std::queue<std::pair<int, int>> q;
  q.push({1, 1});
  int mn = LLONG_MAX;
  while (!q.empty()) {
    auto [d, u] = q.front(); q.pop();
    dep[u] = d;
    a[d]++;
    if (g[u].empty()) {
      mn = std::min(mn, d);
    }
    for (int v : g[u]) {
      q.push({d + 1, v});
    }
  }
  auto s = a;
  for (int i = 1; i <= n; i++) {
    s[i] += s[i - 1];
  }
  std::vector<std::vector<int>> f(mn + 1, std::vector<int>(k + 1));
  f[0][0] = 1;
  int ans = 0;
  for (int i = 1; i <= mn; i++) {
    bool flag = false;
    for (int j = 0; j <= std::min(k, s[i]); j++) {
      if (j >= a[i]) {
        f[i][j] |= f[i - 1][j - a[i]];
      }
      f[i][j] |= (f[i - 1][j] && s[i - 1] - j + a[i] <= n - k);
      flag |= f[i][j];
    }
    if (!flag) {
      std::cout << i - 1 << '\n';
      return;
    }
  }
  std::cout << mn << '\n';
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