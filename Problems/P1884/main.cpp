#include <bits/stdc++.h>
#define N 2001
using namespace std;

struct Node {
  int x, y1, y2;
  bool f;
  bool operator < (const Node &b) const {
    return x < b.x;
  }
} d[N << 2];

struct Seg {
  int l, r, sum;
} cl[N << 2];

int s[N << 2], lazy[N << 2];

void pushup(int p) {
  if (lazy[p]) {
    cl[p].sum = cl[]
  } else
}

void build(int l, int r, int p) {
  cl[p].l = s[l];
  cl[p].r = s[r];
  if (r - l <= 1) {
    cl[p].sum = 0;
  } else {
    int mid = l + (r - l >> 1);
    build(l, mid, p << 1);
    build(mid + 1, r, p << 1 | 1);
    cl[p].sum = cl[p << 1].sum + cl[p << 1 | 1].sum;
  }
}

void update(int y1, int y2, bool flag, int p) {

}

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    d[i] = {x1, y1, y2, true};
    d[i + n] = {x1, y1, y2, false};
    s[i + 1] = y1;
    s[i + 1 + n] = y2;
  }
  sort(d, d + (n << 1));
  sort(s + 1, s + 2 * n + 1);
  build(1, n * 2, 1);
  int ans = 0;
  update(p[0].y1, p[0].y2, p[0].flag, 1);
  for (int i = 1; i < n * 2; i++) {
    ans += (d[i].x - d[i - 1].x) * cl[1].sum;
    update(p[i].y1, p[i].y2, p[i].flag, 1);
  }

}