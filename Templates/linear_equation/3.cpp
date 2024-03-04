// date: 2024-02-28 21:00:00
// tag: 我才知道exgcd可以这么丝滑的解线性同余方程，x,y直接就是答案（部分的

#include <bits/stdc++.h>
#define int long long
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  int g = exgcd(b, a % b, y, x);
  y -= a / b * x;
  return g;
}

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  auto exgcd = [](auto self, int a, int b, int &x, int &y) {
    if (b == 0) {
      x = 1, y = 0;
      return a;
    }
    int g = self(self, b, a % b, y, x);
    y -= a / b * x;
    return g;
  };
  int x, y;
  int g = exgcd(exgcd, a, b, x, y);
  if (c % g) {
    cout << -1 << '\n';
    return;
  }
  int x1 = x * c / g, y1 = y * c / g;
  double dx = -g * x1, dy = g * y1;
  int l = floor(dx / b) +  1, r = ceil(dy / a) - 1;

  if (l <= r) {
    cout << (r - l + 1) << ' ';
    cout << l * b / g + x1 << ' ' << y1 - r * a / g << ' ';
    cout << r * b / g + x1 << ' ' << y1 - l * a / g;
  } else {
    cout << l * b / g + x1 << ' ' << y1 - r * a / g;
  }
  cout << '\n';


  // cout << x1 << ' ' << y1 << '\n';
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