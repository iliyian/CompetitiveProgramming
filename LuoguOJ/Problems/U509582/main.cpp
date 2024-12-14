#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e5;

std::vector<std::pair<int, int>> g[N + 1];
std::vector<int> siz(N + 1), maxx(N + 1), vis(N + 1), len(N + 1), cnt(N + 1);

int rt = 0, sum, n, mid, tot;

void getrt(int u, int p) {
  siz[u] = 1;
  maxx[u] = 0;
  for (auto [v, w] : g[u]) {
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

std::vector<int> d(N * 2 + 1);

void add(int x, int c) {
  x += n; 
  for (int i = x; i <= N * 2; i += i & -i) d[i] += c;
}

int query(int x) {
  int ans = 0;
  x += n;
  for (int i = x; i > 0; i -= i & -i) ans += d[i];
  return ans;
}

std::vector<int> vec, cur;

void calc(int u, int p) {
  cur.push_back(u);
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      cnt[v] = cnt[u] + (w <= mid);
      len[v] = len[u] + 1;
      calc(v, u);
    }
  }
}

void work(int u, int p) {
  vis[u] = 1;
  add(0, 1);
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      cnt[v] = (w <= mid);
      len[v] = 1;
      calc(v, u);
      for (int i : cur) {
        tot += query(cnt[i] * 2 - len[i] - 1);
      }
      while (!cur.empty()) {
        int i = cur.back();
        add(len[i] - cnt[i] * 2, 1);
        vec.push_back(i); cur.pop_back();
      }
    }
  }
  add(0, -1);
  while (!vec.empty()) {
    int i = vec.back();
    add(len[i] - cnt[i] * 2, -1);
    vec.pop_back();
  }
  for (auto [v, w] : g[u]) {
    if (v != p && !vis[v]) {
      sum = siz[v];
      rt = 0;
      getrt(v, 0);
      work(rt, 0);
    }
  }
}

bool check() {
  maxx[0] = INT_MAX;
  std::fill(vis.begin(), vis.end(), 0);
  sum = n;
  tot = 0;
  rt = 0;
  getrt(1, 0);
  work(rt, 0);
  return tot > n * (n - 1) / 2 / 2;
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  std::cin >> n;
  for (int i = 2; i <= n; i++) {
    int x, y, w;
    std::cin >> x >> y >> w;
    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }
  int l = 1, r = n, ans = -1;
  while (l <= r) {
    mid = (l + r) / 2;
    if (check()) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  assert(ans != -1);
  std::cout << ans << '\n';
  return 0;
}