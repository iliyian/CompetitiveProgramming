// date: 2025-08-09 14:16:41
// tag: 为什么3个log还跑得飞快？

#include <bits/stdc++.h>
#define int long long

int v[(int)1e5 + 1];

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i];
    a[i] += a[i - 1];
    b[i] += b[i - 1];
  }
  if (b[n] == 0) {
    std::cout << "0/1" << '\n';
    return;
  }
  auto check = [&](int p, int q) -> bool {
    if (p > q) return false;
    std::vector<int> c(n + 1);
    int r = 0;
    v[r++] = 0;
    for (int i = 1; i <= n; i++) {
      c[i] = p * a[i] - q * b[i];
    }
    if (c[n] < 0) return false;
    for (int i = 1; i <= n; i++) {
      if (c[i] >= 0 && c[i] <= c[n]) {
        if (c[i] >= v[r - 1]) {
          v[r++] = c[i];
        } else {
          *std::upper_bound(v, v + r, c[i]) = c[i];
        }
      }
      if (r >= k + 1) {
        return true;
      }
    }
    return false;
  };
  auto work = [&](auto &&self, int _a, int b, int c, int d) -> void {
    int p = _a + c, q = b + d;
    if (q > a[n]) {
      std::cout << c << '/' << d << '\n';
      return;
    }
    if (check(p, q)) { // left
      for (int i = 30; i >= 0; i--) {
        if (q + (b << i) <= a[n] && check(p + (_a << i), q + (b << i))) { // O(nlognlogvlogv)
          p += _a << i;
          q += b << i;
        }
      }
      self(self, _a, b, p, q);
    } else {
      for (int i = 30; i >= 0; i--) {
        if (q + (d << i) <= a[n] && !check(p + (c << i), q + (d << i))) {
          p += c << i;
          q += d << i;
        }
      }
      self(self, p, q, c, d);
    }
  };
  work(work, 0, 1, 1, 0);;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}