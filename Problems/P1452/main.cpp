// date: 2024/02/22 15:34:07
// tag: 旋转卡壳模板
// wa#01: j应该从1开始
// wa#02: 特判三角形

#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
  int x, y;
  double ang = 0;
  Point operator - (const Point &b) const {
    return Point({x - b.x, y - b.y, 0});
  }
};

void solve() {
  int n;
  cin >> n;
  vector<Point> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    if (i > 1 && (a[i].y < a[1].y || a[i].y == a[1].y && a[i].x < a[1].x)) {
      swap(a[1], a[i]);
    }
  }
  for (int i = 2; i <= n; i++) {
    a[i].ang = atan2(a[i].y - a[1].y, a[i].x - a[1].x);
  }
  auto cross = [&](const Point &x, const Point &y) {
    return x.x * y.y - x.y * y.x;
  };
  auto dis2 = [&](const Point &x, const Point &y) {
    return (x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y);
  };
  sort(a.begin() + 2, a.end(), [&](const Point &x, const Point &y) {
    if (x.ang == y.ang) {
      return dis2(x, a[1]) < dis2(y, a[1]);
    }
    return x.ang < y.ang;
  });

  int top = 0;
  vector<int> st(n + 3);
  st[++top] = 1;
  for (int i = 2; i <= n; i++) {
    while (top >= 2 &&
      cross(a[st[top]] - a[st[top - 1]], a[i] - a[st[top]]) < 0) {
        top--;
    }
    st[++top] = i;
  }
  st[++top] = 1;

  int mx = 0, j = 1;
  if (top <= 4) {
    mx = max(dis2(a[st[1]], a[st[2]]), dis2(a[st[1]], a[st[3]]));
    cout << mx << '\n';
    return;
  }
  for (int i = 1; i < top; i++) {
    while (cross(a[st[j]] - a[st[i]], a[st[j]] - a[st[i + 1]])
      < cross(a[st[j % top + 1]] - a[st[i]], a[st[j % top + 1]] - a[st[i + 1]])) {
        j = j % top + 1;
    }
    mx = max(mx, max(
      dis2(a[st[j]], a[st[i]]), dis2(a[st[j]], a[st[i + 1]])));
  }
  cout << mx << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _ = 1;

  while (_--) {
    solve();
  }

  return 0;
}