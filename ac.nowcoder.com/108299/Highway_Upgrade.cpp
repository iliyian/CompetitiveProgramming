// date: 2025-07-18 10:40:00
// tag: 挺有意思的凸包优化，或者说斜率优化，构成凸包后O(logn)解决类似于min_{i=1}^{n}{y_{i}-kx_{i}}的式子。很难绷的是爆long long了。

#include <bits/stdc++.h>
#include <functional>
#include <random>
#define int long long

/**   静态凸包（with. Point，新版）
 *    2024-04-06: https://qoj.ac/submission/379920)
**/

using i64 = long long;

struct Point {
    i64 x;
    i64 y;
    Point() : x{0}, y{0} {}
    Point(i64 x_, i64 y_) : x{x_}, y{y_} {}
};

__int128_t dot(Point a, Point b) {
    return (__int128_t)1 * a.x * b.x + (__int128_t)1 * a.y * b.y;
}

__int128_t cross(Point a, Point b) {
    return (__int128_t)1 * a.x * b.y - (__int128_t)1 * a.y * b.x;
}

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

auto getHull(std::vector<Point> p) {
    std::sort(p.begin(), p.end(),
        [&](auto a, auto b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
    
    std::vector<Point> hi, lo;
    for (auto p : p) {
        while (hi.size() > 1 && cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0) {
            hi.pop_back();
        }
        while (!hi.empty() && hi.back().x == p.x) {
            hi.pop_back();
        }
        hi.push_back(p);
        while (lo.size() > 1 && cross(lo.back() - lo[lo.size() - 2], p - lo.back()) <= 0) {
            lo.pop_back();
        }
        lo.push_back(p);
        if (lo.empty() || lo.back().x < p.x) {
            lo.push_back(p);
        }
    }
    return std::make_pair(hi, lo);
}

const double inf = INFINITY;

std::mt19937_64 rd(std::random_device{}());

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<std::pair<int, int>>> g(n + 1), h(n + 1);
  std::vector<std::array<int, 4>> e;
  std::vector<int> dis1(n + 1, LLONG_MAX / 3), dis2(n + 1, LLONG_MAX / 3);
  for (int i = 1; i <= m; i++) {
    int x, y, t, w;
    std::cin >> x >> y >> t >> w;
    if (x == y)
      continue;
    g[x].push_back({y, t});
    h[y].push_back({x, t});
    e.push_back({t, w, x, y});
  }
  auto dijkstra = [](std::vector<std::vector<std::pair<int, int>>> &g,
                     std::vector<int> &dis, int s) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        q;
    q.push({dis[s] = 0, s});
    while (!q.empty()) {
      auto [d, u] = q.top();
      q.pop();
      if (dis[u] != d)
        continue;
      for (auto [v, w] : g[u]) {
        if (dis[v] > dis[u] + w) {
          q.push({dis[v] = dis[u] + w, v});
        }
      }
    }
  };
  dijkstra(g, dis1, 1);
  dijkstra(h, dis2, n);
  std::vector<Point> v;
  for (auto &[t, w, x, y] : e) {
    t += dis1[x] + dis2[y];
    v.push_back({-w, t});
  }
  auto [hi, lo] = getHull(v);
  // for (auto [x, y] : hi) {
  //   std::cerr << x << ' ' << y << '\n';
  // }
  // std::cerr << '\n';
  // for (auto [x, y] : lo) {
  //   std::cerr << x << ' ' << y << '\n';
  // }
  int q;
  std::cin >> q;
  while (q--) {
    int k;
    std::cin >> k;
    auto check = [&](int mid, std::vector<Point> &v) -> int {
      return v[mid].y + v[mid].x * k;
    };
    int l = 0, r = lo.size() - 1, ans = -1;
    while (l < r) {
      int mid = (l + r) / 2;
      if (check(mid, lo) <= check(mid + 1, lo))
        r = mid;
      else
        l = mid + 1;
    }
    ans = check(l, lo);
    std::cout << ans << '\n';
  }
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