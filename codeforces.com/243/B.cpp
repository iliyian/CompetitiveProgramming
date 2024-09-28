#include <bits/stdc++.h>
#define int long long
// using namespace std;

constexpr int N = 1e5 + 5;

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int n, m, h, t;
  std::cin >> n >> m >> h >> t;
  std::vector<std::vector<int>> g(n + 1);
  std::vector<std::pair<int, int>> e;
  for (int i = 1; i <= m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    e.push_back({x, y});
  }

  std::bitset<N> vis;
  auto check = [&](int x, int y) {
    vis.reset();
    if (g[x].size() - 1 < h || g[y].size() - 1 < t) return false;
    std::vector<int> ansx, ansy;
    if (g[y].size() >= h + t + 1) std::swap(x, y);
    if (g[x].size() >= h + t + 1) {
      for (auto v : g[y]) {
        if (v != x) {
          ansy.push_back(v);
          vis[v] = true;
        }
      }
      for (int i = 0; i < h + t; i++) {
        if (g[x][i] != y && !vis[g[x][i]]) {
          ansx.push_back(g[x][i]);
        }
      }
    } else {
      int cnt = 0;
      for (auto v : g[x]) {
        if (v != y) {
          vis[v] = true;
          cnt++;
        }
      }
      if (cnt < h) return false;
      for (int v : g[y]) {
        if (v != x) {
          if (vis[v]) {
            if (cnt > h) {
              cnt--;
              vis[v] = false;
              ansy.push_back(v);
            }
          } else {
            ansy.push_back(v);
          }
        }
      }
      if (ansy.size() < t) {
        return false;
      }
      for (int v : g[x]) {
        if (v != y && vis[v]) {
          ansx.push_back(v);
        }
      }
    }

    std::cout << "YES\n";
    std::cout << x << ' ' << y << '\n';
    for (auto v : ansx) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
    for (auto v : ansy) {
      std::cout << v << ' ';
    }
    std::cout << '\n';
    return true;
  };
  for (auto [x, y] : e) {
    if (check(x, y)) {
      return 0;
    }
    if (check(y, x)) {
      return 0;
    }
  }
  std::cout << "NO\n";

  return 0;
}