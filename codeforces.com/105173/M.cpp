// date: 2024-05-21 19:26:10
// tag: 暴力，计算几何
// 感受一下，判断矩形少了一个角，
// 导致(2,2),(0,4),(8,4),(8,8)也被判断成矩形的感觉
// tmd

#include <bits/stdc++.h>
#define int long long
#define eps 1e-9
using namespace std;

struct Point {
  int x, y;
  const Point operator - (const Point &b) const {
    return Point{x - b.x, y - b.y};
  }
};

__int128 dot(const Point &x, const Point &y) {
  return __int128(x.x) * y.x + __int128(x.y) * y.y;
}

__int128 dis2(const Point &x, const Point &y) {
  return __int128(x.x - y.x) * (x.x - y.x) + __int128(x.y - y.y) * (x.y - y.y);
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("M.in", "r", stdin);
  freopen("M.out", "w", stdout);

  int n;
  cin >> n;
  vector<Point> points(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> points[i].x >> points[i].y;
  }



  int ans = 0;
  vector<array<int, 5>> vec;
  unordered_map<int, unordered_set<int>> visrect;
  for (int a = 1; a <= n; a++) {
    auto &A = points[a];
    for (int b = 1; b <= n; b++) {
      auto &B = points[b];
      if (b == a) continue;
      for (int c = 1; c <= n; c++) {
        auto &C = points[c];
        if (c == a || c == b) continue;
        if (dot(B - A, B - C)) continue;
        for (int d = 1; d <= n; d++) {
          auto &D = points[d];
          if (d == a || d == b || d == c) continue;
          if (dot(D - A, D - C)) continue;
          if (dot(B - A, D - A)) continue;


          array<int, 4> rect = {a, b, c, d};
          sort(rect.begin(), rect.end());
          int h1 = rect[0] * 300 + rect[1], h2 = rect[2] * 300 + rect[3];
          

          if (visrect[h1].count(h2)) {
            continue;
          }
          visrect[h1].insert(h2);


          for (int e = 1; e <= n; e++) {
            auto &E = points[e];
            if (e == a || e == b || e == c || e == d) continue;
            if (dis2(A, E) == dis2(B, E) && 
              (dot(A - E, A - D) < 0 || dot(D - A, D - E) < 0)) {
                ans++;
              vec.push_back({a, b, c, d, e});
              continue;
            }
            if (dis2(B, E) == dis2(C, E) &&
              (dot(B - E, B - A) < 0 || dot(A - B, A - E) < 0)) {
                ans++;
              vec.push_back({a, b, c, d, e});
            }
          }
        }
      }
    }
  }
  cout << ans << '\n';
  // for (auto x : vec) {
  //   // sort(x.begin(), x.end());
  //   for (auto i : x) {
  //     cout << i << ' ';
  //   }
  //   cout << '\n';
  // }
  // sort(vec.begin(), vec.end());
  // for (int i = 0; i < vec.size() - 1; i++) {
  //   if (vec[i] == vec[i + 1]) {
  //     assert(false);
  //   }
  // }

  return 0;
}