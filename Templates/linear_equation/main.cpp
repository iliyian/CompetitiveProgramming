// date: 2024/02/03 12:52:32
// tag: 求线性同余方程最小解的模板
// wa#01: 注意最后一步取余是对于 (B / gcd(A, B)) 的，还有本题要注意负数

#include <bits/stdc++.h>
#define int long long
using namespace std;

// x - y + k(m - n) = zl
// zl + k(n - m) = x - y;
// a = l, b = n - m, c = x - y;
// az + bk = c
// az = c (mod b)
// - 1 - k = 
// x - y + (m - n)u = lv
// (n - m)u + lv = x - y;

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1ll, y = 0ll;
    return a;
  };
  int d = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

void solve() {
  int x, y, m, n, l;
  cin >> x >> y >> m >> n >> l;
  int u, v;
  int A = n - m, B = l, C = x - y;
  if (A < 0) {
    A = -A, C = -C;
  }
  int g = exgcd(A, B, u, v);
  if (C % g) {
    cout << "Impossible" << '\n';
    return;
  }
  int k = C / g;
  cout << ((u * k % (B / g)) + (B / g)) % (B / g) << '\n';
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  // int _; cin >> _;
  int _ = 1;
  while (_--) solve();
}