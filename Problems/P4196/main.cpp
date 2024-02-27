// date: 2024-02-26 23:02:17
// tag: stl和数组混搭太难了，索引为1和索引为0开头混搭太难了
// cross前后不能换位置
// wa#01: nan没有特判
// wa#02: nan没有特判

#include <bits/stdc++.h>
#define eps 1e-7
using namespace std;

struct Pt {
  double x = 0, y = 0;
  Pt operator - (Pt b) {
    return Pt{x - b.x, y - b.y};
  };
};

// origin
double cross(Pt a, Pt b) {
  return a.x * b.y - a.y * b.x;
};

double cross(Pt a, Pt b, Pt c) {
  return cross(b - a, c - a);
};

struct Vec {
  Pt s, t;
  double angle = 0;
  Vec() {}
  Vec(const Pt &s, const Pt &t) {
    this->s = s, this->t = t;
    angle = atan2(t.y - s.y, t.x - s.x);
  }
  bool operator < (const Vec &b) const {
    if (abs(angle - b.angle) < eps) {
      return cross(s, b.s, b.t) > 0;
    }
    return angle < b.angle;
  }
};

Pt intersection(Vec a, Vec b) {
  double S1 = cross(a.s, b.t, a.t),
    S2 = cross(a.s, b.s, a.t);
  return Pt{(S1 * b.s.x - S2 * b.t.x) / (S1 - S2), (S1 * b.s.y - S2 * b.t.y) / (S1 - S2)};
}

bool check(Vec a, Vec b, Vec c) {
  Pt p = intersection(b, c);
  return cross(p, a.s, a.t) < 0;
}

void solve() {
  int n;
  cin >> n;
  vector<Vec> a;
  a.push_back(Vec());
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    vector<Pt> points(m + 1);
    for (int j = 1; j <= m; j++) {
      cin >> points[j].x >> points[j].y;
    }
    for (int j = 1; j <= m; j++) {
      a.push_back({points[j], points[j % m + 1]});
    }
  }
  sort(a.begin() + 1, a.end());
  a.erase(unique(a.begin() + 1, a.end(), [](const Vec &x, const Vec &y) {
    return abs(x.angle - y.angle) < eps;
  }), a.end());
  int l = 1, r = 2;
  // 存索引什么的真的不是好主意
  vector<Vec> dq(a.size() + 5);
  dq[l] = a[1], dq[r] = a[2];
  for (int i = 3; i < a.size(); i++) {
    while (l < r && check(a[i], dq[r], dq[r - 1])) r--;
    while (l < r && check(a[i], dq[l], dq[l + 1])) l++;
    dq[++r] = a[i];
  }
  vector<Pt> pts;
  while (l < r && check(a[l], dq[r], dq[r - 1])) r--;
  while (l < r && check(a[r], dq[l], dq[l + 1])) l++;
  for (int i = l; i < r; i++) {
    pts.push_back(intersection(dq[i], dq[i + 1]));
  }
  pts.push_back(intersection(dq[l], dq[r]));
  double ans = 0;
  for (int i = 0; i < pts.size() - 1; i++) {
    ans += cross(pts[i], pts[i + 1]);
  }
  // 不能搞反
  ans += cross(pts.back(), pts.front());
  cout << fixed << setprecision(3) << (isnan(ans) ? 0 : ans / 2) << '\n';
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