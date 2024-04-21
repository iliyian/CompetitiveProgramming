// date: 2024-03-16 17:38:11
// tag: 概率

#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("main.in", "r", stdin);
  freopen("main.out", "w", stdout);

  int w, n, k;
  cin >> w >> n >> k;
  int p = 1e9 + 7;
  auto exgcd = [&](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return;
    }
    self(self, b, a % b, y, x);
    y -= a / b * x;
  };
  int x, y;
  exgcd(exgcd, 2, p, x, y);
  x = (x % p + p) % p;

  int xx = 1;
  while (k) {
    if (k & 1) xx = xx * x % p;
    x = x * x % p;
    k >>= 1;
  }
  cout << w * xx % p << '\n';

  return 0;
}