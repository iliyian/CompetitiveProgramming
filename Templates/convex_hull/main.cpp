#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Point {
  double x, y, ang = 0;
  Point operator - (const Point &b) const {
    return Point({x - b.x, y - b.y, 0});
  };
};

double dis(const Point &x, const Point &y) {
  return sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
}

double cross(const Point &x, const Point &y) {
  return x.x * y.y - x.y * y.x;
}

void solve() {
  int n;
  cin >> n;
  vector<Point> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i].x >> a[i].y;
    if (i > 1 && (a[i].y < a[1].y || (a[i].y == a[1].y && a[i].x < a[1].x))) {
      swap(a[i], a[1]);
    }
  }
  // 这两个循环似乎不能写在一起
  for (int i = 2; i <= n; i++) {
    a[i].ang = atan2(a[i].y - a[1].y, a[i].x - a[1].x);
  }
  sort(a.begin() + 2, a.end(), [&](const Point &x, const Point &y) {
    if (x.ang == y.ang) {
      return dis(x, a[1]) < dis(y, a[1]);
    }
    return x.ang < y.ang;
  });
  int top = 0;
  vector<int> st(n + 2);
  st[++top] = 1;
  for (int i = 2; i <= n; i++) {
    while (top >= 2 &&
      cross(a[st[top]] - a[st[top - 1]], a[i] - a[st[top]]) < 0) {
        top--;
    }
    st[++top] = i;
  }
  double ans = dis(a[st[1]], a[st[top]]);
  for (int i = 1; i < top; i++) {
    ans += dis(a[st[i]], a[st[i + 1]]);
  }
  cout << fixed << setprecision(2) << ans << '\n';
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