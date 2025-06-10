// date: 2025-05-20 20:39:38
// tag: cf比较少见的出了点分治吧，树上log级别的东西好像点分治少不了

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<int> vis(n + 1), siz(n + 1), maxx(n + 1);
  int tot = n, rt = 0;
  auto getrt = [&](auto self, int u, int p) -> void {
    siz[u] = 1;
    maxx[u] = 0;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        self(self, v, u);
        siz[u] += siz[v];
        maxx[u] = std::max(maxx[u], siz[v]);
      }
    }
    maxx[u] = std::max(maxx[u], tot - siz[u]);
    if (maxx[u] < maxx[rt]) {
      rt = u;
    }
  };
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  maxx[0] = LLONG_MAX;
  auto ask1 = [&](std::vector<int> &x, int mid) {
    std::cout << "? 1 " << mid + 1 << ' ';
    for (int i = 0; i <= mid; i++) {
      std::cout << x[i] << ' ';
    }
    std::cout << std::endl;
    int ans;
    std::cin >> ans;
    return ans;
  };
  auto ask2 = [&](int x) {
    std::cout << "? 2 " << x << std::endl;
  };
  int realrt = -1;
  auto work = [&](auto self, int u, int p) -> void {
    std::cerr << "on " << u << '\n';
    vis[u] = 1;
    std::vector<int> vec;
    for (int v : g[u]) {
      if (!vis[v] && v != p) {
        vec.push_back(v);
      }
    }
    int l = 0, r = vec.size() - 1, ans = -1;
    while (l <= r) {
      int mid = (l + r) / 2;
      int p = ask1(vec, mid);
      ask2(u);
      int q = ask1(vec, mid);
      if (std::abs(p - q) != 2 * (mid + 1)) {
        r = mid - 1, ans = mid;
      } else {
        l = mid + 1;
      }
    }
    if (ans == -1) {
      realrt = u;
      return;
    }
    rt = 0;
    tot = siz[vec[ans]];
    getrt(getrt, vec[ans], 0);
    self(self, rt, 0);
  };
  getrt(getrt, 1, 0);
  work(work, rt, 0);
  std::vector<int> ans(n + 1);
  auto dfs = [&](auto self, int u, int p, int sum) -> void {
    std::cout << "? 1 1 " << u << std::endl;
    int res;
    std::cin >> res;
    ans[u] = res - sum;
    for (int v : g[u]) {
      if (v != p) {
        self(self, v, u, sum + ans[u]);
      }
    }
  };
  dfs(dfs, realrt, 0, 0);
  std::cout << "! ";
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " ";
  }
  std::cout << std::endl;
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