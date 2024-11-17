#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = (long long)1e9 + 7;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      char ch;
      std::cin >> ch;
      a[i][j] = ch - '0';
    }
  }
  std::vector<std::vector<int>> g(n * 2 + 1);
  // for (int i = 1; i <= n; i++) {
  //   g[i].push_back(i + n);
  // }
  if (m % 2) {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      cnt += a[i][(m + 1) / 2];
    }
    if (cnt >= 2) {
      std::cout << 0 << '\n';
      return;
    }
  }
  for (int j = 1; j <= m / 2; j++) {
    int r = m - j + 1;
    std::vector<std::pair<int, int>> pos;
    for (int i = 1; i <= n; i++) {
      if (a[i][j] == 1) {
        pos.push_back({i, j});
      }
      if (a[i][r] == 1) {
        pos.push_back({i, r});
      }
      if (pos.size() > 2) {
        std::cout << 0 << '\n';
        return;
      }
    }
    if (pos.size() <= 1) continue;
    if (pos.front().first == pos.back().first) {
      continue;
    }
    int x = pos.front().first, y = pos.back().first;
    // std::cout << pos.front().first << ' ' << pos.front().second << '\n';
    // std::cout << pos.back().first << ' ' << pos.back().second << '\n';
    if (pos.front().second == pos.back().second) {
      g[x].push_back(y + n);
      g[y].push_back(x + n);
      g[x + n].push_back(y);
      g[y + n].push_back(x);
    } else {
      g[x].push_back(y);
      g[y].push_back(x);
      g[x + n].push_back(y + n);
      g[y + n].push_back(x + n);
    }
  }
  std::vector<int> id(n * 2 + 1);
  auto dfs = [&](auto self, int u, int p, int idx) -> void {
    if (id[u]) return;
    id[u] = idx;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, idx);
      }
    }
  };
  int cnt = 0;
  for (int i = 1; i <= n * 2; i++) {
    if (!id[i]) {
      dfs(dfs, i, 0, ++cnt);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (id[i] == id[i + n]) {
      std::cout << 0 << '\n';
      return;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cout << id[i] << ' ' << id[i + n] << " \n"[i == n];
  // }
  int ans = 1;
  cnt /= 2;
  while (cnt--) {
    ans = ans * 2 % mod;
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}