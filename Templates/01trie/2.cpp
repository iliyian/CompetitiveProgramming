// date: 2024-07-28 15:42:20
// tag: 01trie应用，树

#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 2e5 + 5;

std::vector<std::array<int, 2>> otrie(N << 5), etrie(N << 5);
std::vector<int> ocnt(N << 5), ecnt(N << 5);
int otot = 1, etot = 1;

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1);
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  std::vector<int> val(n + 1), dep(n + 1);
  auto dfs = [&](auto self, int u, int p) -> void {
    dep[u] = dep[p] + 1;
    for (auto [v, w] : g[u]) {
      if (v != p) {
        val[v] = val[u] ^ w;
        self(self, v, u);
      }
    }
  };
  dfs(dfs, 1, 0);

  auto oinsert = [&](int x, int c) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!otrie[u][idx]) otrie[u][idx] = ++otot;
      u = otrie[u][idx];
      ocnt[u] += c;
    }
  };

  auto oquery = [&](int x) {
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (ocnt[otrie[u][idx ^ 1]]) {
        u = otrie[u][idx ^ 1];
        ans += 1 << i;
      } else {
        u = otrie[u][idx];
      }
    }
    return ans;
  };

  auto einsert = [&](int x, int c) {
    int u = 1;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (!etrie[u][idx]) etrie[u][idx] = ++etot;
      u = etrie[u][idx];
      ecnt[u] += c;
    }
  };

  auto equery = [&](int x) {
    int u = 1, ans = 0;
    for (int i = 30; i >= 0; i--) {
      int idx = x >> i & 1;
      if (ecnt[etrie[u][idx ^ 1]]) {
        u = etrie[u][idx ^ 1];
        ans += 1 << i;
      } else {
        u = etrie[u][idx];
      }
    }
    return ans;
  };

  // otot = 1, etot = 1;
  for (int i = 1; i <= n; i++) {
    if (dep[i] % 2) {
      oinsert(val[i], 1);
    } else {
      einsert(val[i], 1);
    }
  }

  int k = 0;

  for (int i = 1; i <= m; i++) {
    char op;
    int x, w;
    std::cin >> op;
    if (op == '^') {
      std::cin >> w;
      k ^= w;
    } else {
      std::cin >> x >> w;
      int v = val[x] ^ w, ans = 0;

      if (dep[x] % 2 == 0) v ^= k, einsert(val[x], -1);
      else oinsert(val[x], -1);

      ans = std::max(ans, oquery(v));
      ans = std::max(ans, equery(v ^ k));

      if (dep[x] % 2 == 0) einsert(val[x], 1);
      else oinsert(val[x], 1);
      
      std::cout << ans << ' ';
    }
  }

  for (int i = 1; i <= n; i++) {
    if (dep[i] % 2) {
      oinsert(val[i], -1);
    } else {
      einsert(val[i], -1);
    }
  }

  std::cout << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}