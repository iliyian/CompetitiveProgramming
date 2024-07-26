// date: 2024-07-26 13:30:56
// tag: 模拟，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, q;
  std::cin >> n >> q;
  std::vector<std::vector<int>> g(n + 1);
  int tot = 0;
  std::vector<int> c(n + 1);
  std::vector<int> cnt(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> c[i];
    tot += c[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> pa(n + 1);
  std::unordered_set<int> s0, s1, s2, s3;
  // 虽然但是线性复杂度真的听起来很厉害
  // 虽然常数也许很大？

  auto erase = [&](int u) -> void {
    if (!c[u]) return;
    if (cnt[u] == 0) {
      s0.erase(u);
    } else if (cnt[u] == 1) {
      s1.erase(u);
    } else if (cnt[u] == 2) {
      s2.erase(u);
    } else {
      s3.erase(u);
    }
  };

  auto insert = [&](int u) -> void {
    if (!c[u]) return;
    if (cnt[u] == 0) {
      s0.insert(u);
    } else if (cnt[u] == 1) {
      s1.insert(u);
    } else if (cnt[u] == 2) {
      s2.insert(u);
    } else {
      s3.insert(u);
    }
  };

  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p) {
        pa[v] = u;
        cnt[u] += c[v];
        self(self, v, u);
      }
    }
    insert(u);
  };
  dfs(dfs, 1, 0);

  while (q--) {
    int u;
    std::cin >> u;

    if (c[u]) {
      tot--;

      erase(u);
      c[u] ^= 1;

      erase(pa[u]);

      cnt[pa[u]]--;
      insert(pa[u]);

    } else {
      c[u] ^= 1;
      tot++;

      erase(pa[u]);
      insert(u);

      cnt[pa[u]]++;
      insert(pa[u]);
    }


    if (!s3.empty()) {
      std::cout << "No\n";
      continue;
    }
    if (!s2.empty()) { // 折链
      if (s2.size() > 1 || c[pa[*s2.begin()]]) {
        std::cout << "No\n";
        continue;
      }
      if (s0.size() != 2 || 2 + 1 + s1.size() != tot) {
        std::cout << "No\n";
        continue;
      }
      std::cout << "Yes\n";
      continue;
    }
    if (!s1.empty()) {
      if (s0.size() != 1 || s1.size() + 1 != tot) {
        std::cout << "No\n";
        continue;
      }
      std::cout << "Yes\n";
      continue;
    }

    if (s0.size() == 1) {
      std::cout << "Yes\n";
    } else {
      std::cout << "No\n";
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}