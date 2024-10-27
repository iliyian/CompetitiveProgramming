// date: 2024-10-21 20:29:17
// tag: 区间反转，区间赋值，集合mex，离散化

#include <bits/stdc++.h>
#define lc p << 1
#define rc p << 1 | 1
#define mid (s + t) / 2
#define int long long

const int N = 3e5;

std::vector<int> d(N << 2), val(N << 2, -1), rev(N << 2);
std::vector<int> v;

int id(int x) {
  return std::lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

void pull(int p) {
  // assert(d[p] < d[lc] + d[rc]);
  d[p] = d[lc] + d[rc];
}

void P(int len, int p, int op) {
  if (op == 1) {
    d[p] = len;
    val[p] = 1;
    rev[p] = 0;
  } else if (op == 2) {
    d[p] = 0;
    val[p] = 2;
    rev[p] = 0;
  } else {
    d[p] = len - d[p];
    if (val[p] != -1) val[p] = (val[p] == 1 ? 2 : 1);
    else rev[p] ^= 1;
  }
}

void push(int s, int t, int p) {
  if (val[p] != -1) {
    P(mid - s + 1, lc, val[p]);
    P(t - mid, rc, val[p]);
    val[p] = -1;
  }
  if (rev[p]) {
    P(mid - s + 1, lc, 3);
    P(t - mid, rc, 3);
    rev[p] = 0;
  }
  // val[p] = -1, rev[p] = 0;
}

void modify(int l, int r, int s, int t, int p, int op) {
  if (l > t || r < s) return;
  if (l <= s && t <= r) {
    P(t - s + 1, p, op);
    return;
  }
  push(s, t, p);
  modify(l, r, s, mid, lc, op);
  modify(l, r, mid + 1, t, rc, op);
  pull(p);
}

int query(int s, int t, int p) {
  if (s == t) return s;
  push(s, t, p);
  int llen = mid - s + 1;
  if (d[lc] < llen) return query(s, mid, lc);
  return query(mid + 1, t, rc);
}

signed main() {
  freopen("F.in", "r", stdin);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int m;
  std::cin >> m;
  std::vector<std::array<int, 3>> ask(m + 1);
  for (int i = 1; i <= m; i++) {
    auto &[op, l, r] = ask[i];
    std::cin >> op >> l >> r;
    v.push_back(l);
    v.push_back(r);
    v.push_back(r + 1);
  }
  v.push_back(1);
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  int n = v.size();
  for (int i = 1; i <= m; i++) {
    auto &[op, l, r] = ask[i];
    modify(id(l), id(r), 1, n, 1, op);
    std::cout << v[query(1, n, 1) - 1] << '\n';
  }
  return 0;
}