// date: 2024-07-25 10:01:13
// tag: 完全图欧拉路，构造

// 不知道算不算hierholzer

#include <bits/stdc++.h>
#define int long long
#define N ((int)3e5)
// using namespace std;

std::vector<int> pri;
std::bitset<N + 1> vis;

void solve() {
  int n;
  std::cin >> n;
  int m = 1;
  while (n - 1 > (m % 2 ? (m + 1) * m / 2 : m * m / 2 + 1)) {
    m++;
  }

  std::vector<std::vector<int>> g(m, std::vector<int>(m, 1));
  std::vector<int> cur(m);
  std::vector<int> a;

  if (m % 2 == 0) {
    for (int i = 1; i < m - 1; i += 2) {
      g[i][i + 1] = g[i + 1][i] = false;
    }
  }

  auto dfs = [&](auto self, int u) -> void {
    for (int &i = cur[u]; i < m; i++) {
      if (g[u][i]) {
        g[u][i] = g[i][u] = false;
        self(self, i);
      }
    }
    a.push_back(u);
  };

  dfs(dfs, 0);

  std::reverse(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    std::cout << pri[a[i]] << ' ';
  }

  // std::vector<std::vector<int>> vis(m, std::vector<int>(m));
  // for (int i = 0; i < n - 1; i++) {
  //   if (vis[a[i]][a[i + 1]]) {
  //     std::cout << -1 << '\n';
  //     assert(false);
  //     return;
  //   }
  //   vis[a[i]][a[i + 1]] = vis[a[i + 1]][a[i]] = true;
  // }
  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  for (int i = 2; i <= N; i++) {
    if (!vis[i]) {
      pri.push_back(i);
    }
    for (int p : pri) {
      if (i * p > N) break;
      vis[i * p] = true;
      if (i % p == 0) break;
    }
  }

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}