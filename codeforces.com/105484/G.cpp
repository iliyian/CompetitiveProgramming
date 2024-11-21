#include <bits/stdc++.h>
#define int long long
using namespace std;

int ask(int x, int y) {
  std::cout << "? " << x << ' ' << y << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int x) {
  std::cout << "! " << x << std::endl;
}

void solve() {
  int n;
  std::cin >> n;

  std::vector<std::vector<int>> g(n + 1);
  for (int i = 1; i <= n; i++) {
    int lc, rc;
    std::cin >> lc >> rc;
    if (lc) g[i].push_back(lc), g[lc].push_back(i);
    if (rc) g[i].push_back(rc), g[rc].push_back(i);
  }
  
  std::vector<int> dis(n + 1), vis(n + 1), del(n + 1), dep(n + 1), siz(n + 1);
  std::vector<std::vector<int>> pa(n + 1, std::vector<int>(21));
  int c;
  auto lca = [&](int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 20; i >= 0; i--) {
      if (dep[pa[x][i]] >= dep[y]) {
        x = pa[x][i];
      }
    }
    if (x == y) return x;
    for (int i = 20; i >= 0; i--) {
      if (pa[x][i] != pa[y][i]) {
        x = pa[x][i], y = pa[y][i];
      }
    }
    return pa[x][0];
  };
  auto getd = [&](int x, int y) {
    return dep[x] + dep[y] - dep[lca(x, y)] * 2;
  };
  auto dfs1 = [&](auto self, int u, int p) -> void {
    pa[u][0] = p;
    for (int i = 1; i <= 20; i++) {
      pa[u][i] = pa[pa[u][i - 1]][i - 1];
    }
    dep[u] = dep[p] + 1;
    siz[u] = 1;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u);
        siz[u] += siz[v];
      }
    }
  };
  auto dfs = [&](auto self, int u, int p) -> void {
    for (int v : g[u]) {
      if (v != p && !del[v]) {
        dis[v] = dis[u] + 1;
        if (dis[v] > dis[c]) {
          c = v;
        }
        self(self, v, u);
      }
    }
  };
  // dfs(dfs, 1, 0);
  int rest = n;
  auto getDis = [&]() -> std::pair<int, int> {
    c = 1;
    while (del[c]) {
      c++;
    }
    dfs1(dfs1, c, 0);
    int mn = c;
    for (int i = 1; i <= n; i++) {
      if (!del[i] && std::abs(siz[i] - rest / 2) < std::abs(siz[mn] - rest / 2)) {
        mn = i;
      }
    }
    return {mn, pa[mn][0]};
    // std::fill(dis.begin(), dis.end(), 0);
    // dis[c] = 1;
    // dfs(dfs, c, 0);
    // int d = c;
    // std::fill(dis.begin(), dis.end(), 0);
    // dis[c] = 1;
    // dfs(dfs, c, 0);
    // return {c, d};
  };
  auto getDiameter = [&]() -> std::pair<int, int> {
    dfs1(dfs1, c, 0);
    c = 1;
    while (del[c]) {
      c++;
    }
    std::fill(dis.begin(), dis.end(), 0);
    dis[c] = 1;
    dfs(dfs, c, 0);
    int d = c;
    std::fill(dis.begin(), dis.end(), 0);
    dis[c] = 1;
    dfs(dfs, c, 0);
    return {c, d};
  };
  while (rest > 1) {
    auto [x, y] = (rest <= 3 ? getDiameter() : getDis());

    // std::cout << rest << '\n';
    int ans = ask(x, y);
    // std::cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
      if (!del[i]) {
        int dx = getd(i, x), dy = getd(i, y);
        if (dx == dy && ans != 1) {
          del[i] = true;
          rest--;
        } else if (dx < dy && ans != 0) {
          del[i] = true;
          rest--;
        } else if (dx > dy && ans != 2) {
          del[i] = true;
          rest--;
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      std::cout << del[i] << " \n"[i == n];
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!del[i]) {
      answer(i);
      return;
    }
  }
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