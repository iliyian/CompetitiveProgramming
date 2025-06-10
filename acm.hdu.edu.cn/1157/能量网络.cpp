#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> x(n + 1), y(n + 1), z(n + 1);
  std::vector<int> xx(m + 1), yy(m + 1), zz(m + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> x[i] >> y[i] >> z[i];
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    xx[i] = x[u] + x[v];
    yy[i] = y[u] + y[v];
    zz[i] = z[u] + z[v];
  }
  std::vector<std::array<int, 3>> edges;
  std::vector<int> p(m + 1);

  std::iota(p.begin() + 1, p.end(), 1);
  std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
    return xx[u] < xx[v];
  });
  for (int i = 2; i <= m; i++) {
    edges.push_back({xx[p[i]] - xx[p[i - 1]], p[i - 1], p[i]});
  }
  
  std::iota(p.begin() + 1, p.end(), 1);
  std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
    return yy[u] < yy[v];
  });
  for (int i = 2; i <= m; i++) {
    edges.push_back({yy[p[i]] - yy[p[i - 1]], p[i - 1], p[i]});
  }

  std::iota(p.begin() + 1, p.end(), 1);
  std::sort(p.begin() + 1, p.end(), [&](const int &u, const int &v) {
    return zz[u] < zz[v];
  });
  for (int i = 2; i <= m; i++) {
    edges.push_back({zz[p[i]] - zz[p[i - 1]], p[i - 1], p[i]});
  }

  std::sort(edges.begin(), edges.end());
  std::vector<int> pa(m + 1), siz(m + 1, 1);
  std::iota(pa.begin(), pa.end(), 0);
  auto find = [&](auto self, int x) -> int {return x == pa[x] ? x : pa[x] = self(self, pa[x]);};
  auto merge = [&](int x, int y) {
    x = find(find, x), y = find(find, y);
    if (x == y) return false;
    if (siz[x] > siz[y]) std::swap(x, y);
    siz[y] += siz[x];
    pa[x] = y;
    return true;
  };
  int ans = 0;
  for (auto [d, u, v] : edges) {
    if (merge(u, v)) {
      ans += d;
    }
  }
  std::cout << ans << '\n';
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