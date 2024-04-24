// date: 2024-04-25 00:47:24
// tag: 暴力，数学

#include <bits/stdc++.h>
#define N 200000
using namespace std;

bitset<N + 1> alive;
vector<int> a(N + 1);

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  bool f = true;
  while (f) {
    f = false;
    for (int i = 1; i <= n; i++) {
      int x = i, y = (i + 1) % n, z = (i + 2) % n, w = (i + 3) % n;
      if (y == 0) y = n;
      if (z == 0) z = n;
      if (w == 0) w = n;
      if (a[x] && a[y] && a[z] && a[w]) {
        f = true;
        break;
      }
    }
    for (int i = 1; i <= n; i++) {
      int nxt = (i + 1) % n;
      if (nxt == 0) nxt = n;
      a[nxt] = max(0, a[nxt] - a[i]);
    }
  }
  auto adv = [&](int x, int t) {
    x = (x + t) % n;
    if (x == 0) x = n;
    return x;
  };
  alive.reset();
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) continue;
    int nxt = adv(i, 1), len = 1;
    while (a[nxt]) nxt = adv(nxt, 1), len++;
    if (len == 1) continue;
    else if (len == 2 || len == 3) {
      alive[adv(i, 1)] = true;
      cnt++;
    } else {
      alive[adv(i, 1)] = true;
      cnt++;
      int x = a[adv(i, 1)], y = a[adv(i, 2)], z = a[adv(i, 3)];
      if (adv(i, 3) == 2) {
        z = max(0, z - y);
      }
      int lst = y % x;
      int t = (y - x - lst) / x + 1;
      long long sum = ((long long)y - x + lst) * t / 2;
      if (z > sum) {
        // if (adv(i, 3) == 2) {
        //   cout << '!' << '\n';
        //   cout << x << ' ' << y << ' ' << z << '\n';
        // }
        alive[adv(i, 3)] = true;
        cnt++;
      }
    }
  }
  cout << cnt << '\n';
  for (int i = 1; i <= n; i++) {
    if (alive[i]) {
      cout << i << ' ';
    }
  }
  cout << '\n';
}

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  freopen("E2.in", "r", stdin);
  freopen("E2.out", "w", stdout);

  int _;
  cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}