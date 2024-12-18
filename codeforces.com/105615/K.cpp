// date: 2024-12-17 21:14:04
// tag: 点分治
// 先改了很久的读错题的问题

// 然后改了很久的次小值比最小值大的问题，不知道为什么更新会出现这种情况
// 一定要注意次小值和最小值之间的相对关系啊！！！！可能就是这里wa了

#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e5;

std::vector<int> maxx(N + 1), siz(N + 1), vis(N + 1), a(N + 1);
std::vector<int> g[N + 1];
int rt = 0, sum = 0, n;
std::vector<int> ans(N + 1, INT_MAX);

void getrt(int u, int p) {
  siz[u] = 1;
  maxx[u] = 0;
  for (int v : g[u]) {
    if (!vis[v] && v != p)  {
      getrt(v, u);
      siz[u] += siz[v];
      maxx[u] = std::max(maxx[u], siz[v]);
    }
  }
  maxx[u] = std::max(maxx[u], sum - maxx[u]);
  if (maxx[u] < maxx[rt]) {
    rt = u;
  }
}

std::vector<std::array<int, 4>> cur;

void calc(int u, int p, int t, int x, int d) {
  x ^= a[u];
  cur.push_back({x, d, t, u});
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u, t, x, d + 1);
    }
  }
}

std::vector<int> dis(N + 1, INT_MAX);
std::vector<std::array<int, 3>> mn1(1 << 21, {INT_MAX, 0, 0}), mn2(1 << 21, {INT_MAX, 0, 0});

void update(int a, int b, int d) {
  if (std::tie(dis[a], ans[a]) > std::tie(d, b)) {
    dis[a] = d, ans[a] = b;
  }
  if (std::tie(dis[b], ans[b]) > std::tie(d, a)) {
    dis[b] = d, ans[b] = a;
  }
}

void work(int c, int p) {
  vis[c] = 1;
  // std::cout << c << '\n';
  for (int v : g[c]) {
    if (!vis[v] && v != p) {
      calc(v, c, v, 0, 1);
    }
  }
  for (auto [x, d, t, u] : cur) {
    if ((x ^ a[c]) == 0) {
      update(c, u, d);
    }
    if (mn1[x][1] == t) {
      if (std::tie(mn1[x][0], mn1[x][2]) > std::tie(d, u)) {
        mn1[x] = {d, t, u};
      }
    } else if (mn2[x][1] == t) {
      if (std::tie(mn2[x][0], mn2[x][2]) > std::tie(d, u)) {
        mn2[x] = {d, t, u};
      }
    } else {
      if (std::tie(mn1[x][0], mn1[x][2]) > std::tie(d, u)) {
        mn2[x] = mn1[x];
        mn1[x] = {d, t, u};
      } else if (std::tie(mn2[x][0], mn2[x][2]) > std::tie(d, u)) {
        mn2[x] = {d, t, u};
      }
    }
    if (std::tie(mn2[x][0], mn2[x][2]) < std::tie(mn1[x][0], mn1[x][2])) {
      std::swap(mn2[x], mn1[x]);
    }
  }
  for (auto [x, d, t, u] : cur) {
    x ^= a[c];
    if (mn1[x][1] == t) {
      if (mn2[x][0] == INT_MAX) continue;
      update(u, mn2[x][2], mn2[x][0] + d);
    } else {
      if (mn1[x][0] == INT_MAX) continue;
      update(u, mn1[x][2], mn1[x][0] + d);
    }
  }
  for (auto [x, d, t, u] : cur) {
    mn1[x] = mn2[x] = {INT_MAX, 0, 0};
  }
  cur.clear();
  for (int v : g[c]) {
    if (v != p && !vis[v]) {
      sum = siz[v];
      rt = 0;
      getrt(v, 0);
      getrt(rt, 0);
      work(rt, 0);
      // work(v, c);
    }
  }
}

void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  maxx[rt] = INT_MAX;
  sum = n;
  getrt(1, 0);
  getrt(rt, 0);
  work(rt, 0);
  for (int i = 1; i <= n; i++) {
    std::cout << (ans[i] == INT_MAX ? 0 : ans[i]) << '\n';
  }
  // std::cout << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("K.in", "r", stdin);
#endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
