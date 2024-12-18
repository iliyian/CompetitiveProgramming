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

std::vector<std::array<int, 3>> cur;

void calc(int u, int p, int t, int x) {
  x ^= a[u];
  cur.push_back({x, u, t});
  for (int v : g[u]) {
    if (v != p && !vis[v]) {
      calc(v, u, t, x);
    }
  }
}

std::vector<std::array<int, 2>> mn1(1 << 21, {INT_MAX, 0}), mn2(1 << 21, {INT_MAX, 0});

void work(int c, int p) {
  vis[c] = 1;
  // std::cout << c << '\n';
  for (int v : g[c]) {
    if (!vis[v] && v != p) {
      calc(v, c, v, 0);
    }
  }
  for (auto [x, u, t] : cur) {
    if ((x ^ a[c]) == 0) {
      ans[c] = std::min(ans[c], u);
      ans[u] = std::min(ans[u], c);
    }
    if (mn1[x][1] == t) {
      if (mn1[x][0] > u) {
        mn1[x] = {u, t};
      }
    } else if (mn2[x][1] == t) {
      if (mn2[x][0] > u) {
        mn2[x] = {u, t};
      }
    } else {
      if (mn1[x][0] > u) {
        mn2[x] = mn1[x];
        mn1[x] = {u, t};
      } else if (mn2[x][0] > u) {
        mn2[x] = {u, t};
      }
    }
  }
  for (auto [x, u, t] : cur) {
    if (mn1[x][1] == t) {
      ans[u] = std::min(ans[u], mn2[x][0]);
    } else {
      ans[u] = std::min(ans[u], mn1[x][0]);
    }
  }
  for (auto [x, u, t] : cur) {
    mn1[x] = mn2[x] = {INT_MAX, 0};
  }
  cur.clear();
  for (int v : g[c]) {
    if (v != p && !vis[v]) {
      sum = siz[v];
      rt = 0;
      getrt(v, 0);
      work(rt, 0);
    }
  }
}

std::vector<int> dis(N + 1, INT_MAX);

void update(int a, int b, int d) {
  if (std::tie(dis[a], ans[a]) > std::tie(d, b)) {
    dis[a] = d, ans[a] = b;
  }
  if (std::tie(dis[b], ans[b]) > std::tie(d, a)) {
    dis[b] = d, ans[b] = a;
  }
}

void dfs(int u, int p, int rt, int x, int d) {
  x ^= a[u];
  if (x == 0 && u != rt) {
    update(u, rt, d);
  }
  for (int v : g[u]) {
    if (v != p) {
      dfs(v, u, rt, x, d + 1);
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
  for (int i = 1; i <= n; i++) {
    dfs(i, 0, i, 0, 0);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (ans[i] == INT_MAX ? 0 : ans[i]) << '\n';
  }
}

signed main() {
// #ifndef ONLINE_JUDGE
// 	freopen("K.in", "r", stdin);
// #endif
	std::cin.tie(0)->sync_with_stdio(false);
	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
