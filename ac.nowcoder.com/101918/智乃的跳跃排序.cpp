#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  std::map<int, int> pos;
  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (i + k <= n) {
      g[i].push_back(i + k);
      g[i + k].push_back(i);
    }
  }
  // std::cerr << '\n';
  std::vector<int> id1(n + 1);
  int tot1 = 0;
  auto dfs = [&](auto self, int u) -> void {
    id1[u] = tot1;
    for (int v : g[u]) {
      if (!id1[v]) {
        self(self, v);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!id1[i]) {
      ++tot1;
      dfs(dfs, i);
    }
  }
  std::vector<std::vector<int>> val1(tot1 + 1), ps1(tot1 + 1);
  for (int i = 1; i <= n; i++) {
    // std::cerr << id[i] << ' ';
    val1[id1[i]].push_back(a[i]);
    ps1[id1[i]].push_back(i);
  }
  // std::cerr << '\n';
  for (int i = 1; i <= tot1; i++) {
    std::sort(val1[i].begin(), val1[i].end());
    int j = 0;
    while (j < val1[i].size()) {
      a[ps1[i][j]] = val1[i][j];
      j++;
    }
  }

  
  std::vector<std::vector<int>> gg(n + 1);
  for (int i = 1; i <= n; i++) {
    pos[a[i]] = i;
  }
  for (int i = 1; i <= n; i++) {
    if (pos.count(a[i] - k)) {
      gg[i].push_back(pos[a[i] - k]);
    }
    if (pos.count(a[i] + k)) {
      gg[i].push_back(pos[a[i] + k]);
    }
  }
  std::vector<int> id2(n + 1);
  int tot2 = 0;
  auto dfs2 = [&](auto self, int u) -> void {
    id2[u] = tot2;
    for (int v : gg[u]) {
      if (!id2[v]) {
        self(self, v);
      }
    }
  };
  for (int i = 1; i <= n; i++) {
    if (!id2[i]) {
      ++tot2;
      dfs2(dfs2, i);
    }
  }
  
  std::vector<std::vector<int>> val2(tot2 + 1), ps2(tot2 + 1);
  for (int i = 1; i <= n; i++) {
    val2[id2[i]].push_back(a[i]);
    ps2[id2[i]].push_back(i);
  }
  for (int i = 1; i <= tot2; i++) {
    std::sort(val2[i].begin(), val2[i].end());
    int j = 0;
    while (j < val2[i].size()) {
      a[ps2[i][j]] = val2[i][j];
      j++;
    }
  }
  // for (int i = 1; i <= n; i++) {
  //   std::cerr << a[i] << ' ';
  // }
  // std::cerr << '\n';
  std::cout << (std::is_sorted(a.begin() + 1, a.end()) ? "Yes" : "No") << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}