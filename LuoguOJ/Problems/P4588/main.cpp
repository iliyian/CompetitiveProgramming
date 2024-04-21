// date: 2024-03-21 12:36:15
// tag: 线段树
// wa#01: 想成简单暴力了，应该是带mod的除法的问题

#include <bits/stdc++.h>
#define int long long
#define lc p << 1
#define rc p << 1 | 1
#define N 100005
using namespace std;

int d[N << 2], n, M;

void pushup(int p) {
  d[p] = d[lc] * d[rc] % M;
}

void build(int l, int r, int p) {
  if (l == r) {
    d[p] = 1;
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, lc);
  build(mid + 1, r, rc);
  pushup(p);
}

void modify(int x, int c, int s, int t, int p) {
  if (x == s && x == t) {
    d[p] = c;
    return;
  }
  int mid = (s + t) / 2;
  if (x <= mid) modify(x, c, s, mid, lc);
  else modify(x, c, mid + 1, t, rc);
  pushup(p);
}

void solve() {
  cin >> n >> M;
  build(1, n, 1);
  for (int i = 1; i <= n; i++) {
    int op, x;
    cin >> op >> x;
    if (op == 1) {
      modify(i, x, 1, n, 1);
    } else {
      modify(x, 1, 1, n, 1);
    }
    cout << d[1] << '\n';
  }
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}