// date: 2024-05-18 20:46:28
// tag: 概率，数学

#include <bits/stdc++.h>
#define int long long
#define mod ((int)1e9 + 7)
using namespace std;

void exgcd(int a, int b, int &x, int &y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}

int inv(int a) {
  int x, y;
  exgcd(a, mod, x, y);
  return (x % mod + mod) % mod;
}

void solve() {
  int n, m, rb, cb, rd, cd, p;
  cin >> n >> m >> rb >> cb >> rd >> cd >> p;
  int x = rb, y = cb, dx = -1, dy = -1, cnt = 0;
  set<tuple<int, int, int, int>> s;
  int ansa = 0, ansx = 1;
  int p_fail = (100 - p) * inv(100) % mod;
  for (;;) {
    if (x + dx > n || x + dx < 1) dx = -dx;
    if (y + dy > m || y + dy < 1) dy = -dy;

    if (s.find({x, y, dx, dy}) != s.end()) {
      break;
    }
    s.insert({x, y, dx, dy});

    int curp = 1;

    x += dx, y += dy;

    if (x == rd || y == cd) {
      curp = p_fail;
    }
    ansa = (ansa + 1) * curp % mod;
    ansx = ansx * curp % mod;

  }
  cout << ansa * inv(mod + 1 - ansx) % mod << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}