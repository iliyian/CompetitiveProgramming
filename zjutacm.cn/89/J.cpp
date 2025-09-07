#include <bits/stdc++.h>
#define int long long

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
} // 这里吃过大亏

Point operator+(Point a, Point b) {
    return Point(a.x + b.x, a.y + b.y);
}

Point operator-(Point a, Point b) {
    return Point(a.x - b.x, a.y - b.y);
}

// 凸包板子
auto getHull(std::vector<Point> pp) {
    std::sort(pp.begin(), pp.end(),
        [&](auto a, auto b) {
            return a.x < b.x || (a.x == b.x && a.y < b.y);
        });
    
    std::vector<Point> hi, lo;
    for (auto p : pp) {
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

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<Point> px1, py1, px2, py2;
  for (int i = 1; i <= n; i++) {
    int _x, _y, _w;
    std::cin >> _x >> _y >> _w;
    // 曼哈顿距离转切比雪夫距离
    int x = _x + _y, y = _x - _y;
    // 存储四种点对的值，k和y
    px1.push_back({-_w, x * _w});
    px2.push_back({_w, -x * _w});
    py1.push_back({-_w, y * _w});
    py2.push_back({_w, -y * _w});
  }
  // 依次得到四种情况下的凸包
  auto h1 = getHull(px1);
  auto h2 = getHull(px2);
  auto h3 = getHull(py1);
  auto h4 = getHull(py2);
  // 求给定凸包上的值，这里的.x也就是k
  auto calc = [&](std::vector<Point> &h, int mid, int x) {
    return h[mid].y + h[mid].x * x;
  };
  // 因为分了四份做，所以这里写一个函数处理
  auto get = [&](std::vector<Point> &h, int x) {
    int l = 0, r = h.size() - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      // 我们对差分值进行二分，达到三分的效果，时间复杂度更优
      if (calc(h, mid, x) <= calc(h, mid + 1, x)) l = mid + 1;
      else r = mid;
    }
    return calc(h, l, x);
  };
  int ans = LLONG_MAX;
  for (int i = 1; i <= m; i++) {
    int mx = 0, _x, _y;
    std::cin >> _x >> _y;
    // 曼哈顿距离转切比雪夫距离
    int x = _x + _y, y = _x - _y;
    // 这里我们只考虑上凸包
    mx = std::max(mx, get(h1.first, x));
    mx = std::max(mx, get(h2.first, x));
    mx = std::max(mx, get(h3.first, y));
    mx = std::max(mx, get(h4.first, y));
    // 题目要最大值最小
    ans = std::min(ans, mx);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;

  while (t--) {
    solve();
  }

  return 0;
}