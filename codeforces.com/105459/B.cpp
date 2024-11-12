// date: 2024-11-01 22:41:04
// tag: 凸包，贪心，双指针

#include <bits/stdc++.h>
#define int long long
using namespace std;

using i64 = long long;

struct Point {
  i64 x;
  i64 y;
  int id;
  Point() : x{0}, y{0} {}
  Point(i64 x_, i64 y_) : x{x_}, y{y_} {}
};

i64 dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
i64 cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
bool operator==(Point a, Point b) {return a.x == b.x && a.y == b.y;}

i64 S(Point a, Point b, Point c) {return cross(a - b, a - c);};

auto getHull(vector<Point> p) {
  sort(p.begin(), p.end(),
       [&](auto a, auto b) { return a.x < b.x || (a.x == b.x && a.y < b.y); });
  vector<Point> hi, lo;
  for (auto p : p) {
    while (hi.size() > 1 &&
           cross(hi.back() - hi[hi.size() - 2], p - hi.back()) >= 0) {
      hi.pop_back();
    }
    while (!hi.empty() && hi.back().x == p.x) {
      hi.pop_back();
    }
    hi.push_back(p);
    while (lo.size() > 1 &&
           cross(lo.back() - lo[lo.size() - 2], p - lo.back()) <= 0) {
      lo.pop_back();
    }
    if (lo.empty() || lo.back().x < p.x) {
      lo.push_back(p);
    }
  }
  return make_pair(hi, lo);
}

const double inf = INFINITY;

void solve() {
  int n;
  std::cin >> n;
  std::vector<Point> a(n);
  for (int i = 0; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[i].x = x, a[i].y = y, a[i].id = i;
  }
  std::vector<int> vis(n + 1);

  auto [b, lo] = getHull(a);
  if (lo.back() == b.back()) lo.pop_back();
  // if (lo.front() == b.front()) lo.erase(lo.begin());
  for (int i = lo.size() - 1; i >= 0; i--) {
    b.push_back(lo[i]);
  }

  for (auto v : b) {
    vis[v.id] = true;
  }
  std::vector<Point> c;
  for (int i = 0; i < n; i++) {
    if (!vis[i]) {
      c.push_back(a[i]);
    }
  }
  auto [d, low] = getHull(c);
  if (d.empty() || low.empty()) {
    std::cout << -1 << '\n';
    return;
  }
  if (low.back() == d.back()) low.pop_back();
  // if (low.front() == d.front()) low.erase(low.begin());
  for (int i = low.size() - 1; i >= 0; i--) {
    d.push_back(low[i]);
  }
  // for (auto v : d) {
  //   std::cout << v.x << ' ' << v.y << '\n';
  // }
  // std::cout << '\n';
  // for (auto v : b) {
  //   std::cout << v.x << ' ' << v.y << '\n';
  // }
  int s = 0;
  for (int i = 1; i < b.size() - 1; i++) {
    s += std::abs(S(b[0], b[i], b[i + 1]));
  }
  // std::cout << s << '\n';

  if (b.back() == b.front()) b.pop_back();
  int j = 0, ans = 0;
  for (int i = 0; i < b.size(); i++) {
    while (std::abs(S(b[i], b[(i + 1) % b.size()], d[j]))
       > std::abs(S(b[i], b[(i + 1) % b.size()], d[(j + 1) % d.size()])))
        j = (j + 1) % d.size();
    ans = std::max(ans, s - std::abs(S(b[i], b[(i + 1) % b.size()], d[j])));
  }
  std::cout << ans << '\n';
}

signed main() {
  int t;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}