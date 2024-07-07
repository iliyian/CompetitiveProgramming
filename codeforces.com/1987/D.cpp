// date: 2024-07-03 22:11:25
// tag: 记忆化搜索，dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    cnt[a[i]]++;
  }
  int tot = 0;
  std::vector<int> id(n + 1);
  for (int i = 1; i <= n; i++) {
    if (cnt[i]) {
      id[++tot] = i;
    }
  }

  std::vector<std::vector<int>> f(n + 1, std::vector<int>(n + 1, -1));
  
  auto dfs = [&](auto self, int x, int t) -> int {
    if (x > tot) return 0;
    if (f[x][t] != -1) return f[x][t];
    int ans = self(self, x + 1, t + 1) + 1;
    if (t >= cnt[id[x]]) {
      ans = std::min(ans, self(self, x + 1, t - cnt[id[x]]));
    }
    return f[x][t] = ans;
  };
  std::cout << dfs(dfs, 1, 0) << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}