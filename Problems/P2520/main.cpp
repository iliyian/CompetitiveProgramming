// date: 2024/02/02 16:58:33
// tag: 裴蜀定理的综合应用
// 属于死都想不出来

#include <bits/stdc++.h>
#define int long long
using namespace std;

// (a, b), (b, a), (a, -b), (b, -a);
// ka + wb + qa + cb = x, kb + wa - qb - ca = y;
// (k + q)a + (w + c)b = x
// (k - q)b + (w - c)a = y
// gcd(a, b) | x
// gcd(a, b) | y
// ax+by=c, gcd(a,b)|c
// 4x+6y=8, gcd(4,6)|8
// f = k + q, g = k - q, h = w + c, i = w - c;
// k = (f + g) / 2, q = (f - g) / 2;
// 2 | f + g, 2 | f - g;
// 2 | h - i, 2 | h + i;
// ax + by = d => (nx + my)gcd(a, b) = d;
// 1. f, g even, h, i even:
//   2gcd(a, b) | d, 2gcd(a, b) | e;
// 2. f, g even, h, i odd:
//   fa + (h + 1)b = d + b;
//   gb + (i + 1)a = d + a;
//   (nx + my)gcd(a, b) = d + b;
//   2gcd(a, b) | d + b, 2gcd(a, b) | e + a;
// 3. f, g odd, h, i even:
//   (f + 1)a + hb = d + a;
//   (g + 1)b + ia = e + b;
//   2gcd(a, b) | d + a, 2gcd(a, b) | e + b;
//   (d + a) = (e + b) = 0 (mod 2gcd(a, b))
// 4. f, g, odd, h, i, odd:
//   (f + 1)a + (h + 1)b = d + a + b;
//   (g + 1)b + (i + 1)a = e + a + b;
//   2gcd(a, b) | d + a + b, 2gcd(a, b) | e + a + b;
//   (d + a + b) = (e + a + b) = 0 (mod 2gcd(a, b))

bool isMod(int x, int y, int k) {
  return x % k == 0 && y % k == 0;
}

void solve() {
  int a, b, x, y;
  cin >> a >> b >> x >> y;
  int k = gcd(a, b) * 2;
  if (isMod(x, y, k) || isMod(x + a, y + b, k) || isMod(x + b, y + a, k) || isMod(x + a + b, y + a + b, k))
    cout << "Y\n";
  else
    cout << "N\n";
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);
  int _; cin >> _;
  while (_--) solve();
}