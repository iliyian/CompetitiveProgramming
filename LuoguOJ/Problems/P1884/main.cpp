#include <bits/stdc++.h>
#define N 1024
#define int long long
using namespace std;

struct Seg {
  int l, r, sum;
} segs[N << 3];

struct Mat {
  int x, y1, y2, f;
  bool operator < (const Mat &b) const {
    return x < b.x;
  }
} mats[N << 3];

int v[N << 3], laz[N << 3];

void pushup(int p) {
  if (laz[p]) {
    segs[p].sum = segs[p].r - segs[p].l;
  } else {
    segs[p].sum = segs[p * 2].sum + segs[p * 2 + 1].sum;
  }
}

void build(int s, int t, int p) {
  segs[p].l = v[s], segs[p].r = v[t];
  if (t - s > 1) {
    int mid = (s + t) / 2;
    build(s, mid, p * 2);
    build(mid, t, p * 2 + 1);
    pushup(p);
  }
}

void update(int y1, int y2, int f, int p) {
  if (segs[p].l == y1 && segs[p].r == y2) {
    laz[p] += f;
  } else {
    if (segs[p * 2].r > y1)
      update(y1, min(y2, segs[p * 2].r), f, p * 2);
    if (segs[p * 2 + 1].l < y2)
      update(max(y1, segs[p * 2 + 1].l), y2, f, p * 2 + 1);
  }
  pushup(p);
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("data.in", "r", stdin);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    mats[i] = {x1, y2, y1, 1};
    mats[i + n] = {x2, y2, y1, -1};
    v[i + 1] = y1, v[i + n + 1] = y2;
  }
  sort(v + 1, v + n * 2 + 1);
  sort(mats, mats + n * 2);
  build(1, n << 1, 1);

  int ans = 0;
  for (int i = 0; i < 2 * n - 1; i++) {
    update(mats[i].y1, mats[i].y2, mats[i].f, 1);
    ans += (mats[i + 1].x - mats[i].x) * segs[1].sum;
  }
  cout << ans;
  return 0;
}