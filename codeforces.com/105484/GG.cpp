// date: 2024-11-18 21:10:24
// tag: icpc2024nanjing
// 点分治

#include <bits/stdc++.h>
#define int long long
using namespace std;

std::vector<int> vis, siz, dis, maxx;
std::vector<std::vector<int>> g;
int rt = 0, sum, n;

int ask(int x, int y) {
  // for (int i = 1; i <= n; i++) {
  //   std::cout << vis[i] << " \n"[i == n];
  // }
  std::cout << "? " << x << ' ' << y << std::endl;
  int ans;
  std::cin >> ans;
  return ans;
}

void answer(int x) {
  std::cout << "! " << x << std::endl;
}

void getrt(int u, int p) {
  siz[u] = 1;
  maxx[u] = 0;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      getrt(v, u);
      siz[u] += siz[v];
      maxx[u] = std::max(maxx[u], siz[v]);
    }
  }
  maxx[u] = std::max(maxx[u], sum - siz[u]);
  if (maxx[u] < maxx[rt]) {
    rt = u;
  }
}

void del(int u, int p) {
  if (vis[u]) return;
  vis[u] = true;
  siz[u] = 0;
  sum--;
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      del(v, u);
    }
  }
}

void work(int u, int p) {
  if (sum == 1) {
    answer(u);
    return;
  }
  if (sum == 2) {
    int x = 1;
    while (vis[x]) x++;
    int y = x + 1;
    while (vis[y]) y++;
    int ans = ask(x, y);
    if (ans == 0) {
      answer(x);
    } else {
      answer(y);
    }
    return;
  }
  rt = 0;
  getrt(u, 0);
  // std::cout << "rt: " << rt << '\n';
  std::vector<int> id(g[rt].size());
  std::iota(id.begin(), id.end(), 0);
  std::sort(id.begin(), id.end(), [&](const int &x, const int &y) {
    return siz[g[rt][x]] > siz[g[rt][y]];
  });
  int ans = ask(g[rt][id[0]], g[rt][id[1]]);
  assert(g[rt].size() <= 3);
  for (int i = 0; i < g[rt].size(); i++) {
    if (ans == 0 && i != id[0]) {
      del(g[rt][i], rt);
    } else if (ans == 2 && i != id[1]) {
      del(g[rt][i], rt);
    } else if (ans == 1 && (i == id[0] || i == id[1])) {
      del(g[rt][i], rt);
    }
  }
  if (ans != 1) {
    vis[rt] = true, sum--, siz[rt] = 0;
  } else {
    work(rt, 0);
    return;
  }
  for (int i = 0; i < g[rt].size(); i++) {
    if (!vis[g[rt][i]]) {
      work(g[rt][i], rt);
      return;
    }
  }
}

void solve() {
  std::cin >> n;
  vis.assign(n + 1, 0);
  siz.assign(n + 1, 0);
  g.assign(n + 1, {});
  maxx.assign(n + 1, INT_MAX);
  sum = n;

  for (int i = 1; i <= n; i++) {
    int lc, rc;
    std::cin >> lc >> rc;
    if (lc) g[i].push_back(lc), g[lc].push_back(i);
    if (rc) g[i].push_back(rc), g[rc].push_back(i);
  }

  work(1, 0);
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