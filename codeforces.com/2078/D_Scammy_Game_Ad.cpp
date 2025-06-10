// date: 2025-04-04 17:26:54
// tag: 倒过来的dp

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<char> a(n + 1), c(n + 1);
  std::vector<int> b(n + 1), d(n + 1);
  int l = 1, r = 1, t = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i] >> b[i] >> c[i] >> d[i];
  }
  std::vector<std::array<int, 2>> f(n + 2, {0, 0});
  f[n + 1][0] = f[n + 1][1] = 1;
  for (int i = n; i >= 1; i--) {
    if (a[i] == '+') {
      f[i][0] = f[i + 1][0];
    } else {
      f[i][0] = f[i + 1][0] + (b[i] - 1) * std::max(f[i + 1][0], f[i + 1][1]);
    }
    if (c[i] == '+') {
      f[i][1] = f[i + 1][1];
    } else {
      f[i][1] = f[i + 1][1] + (d[i] - 1) * std::max(f[i + 1][0], f[i + 1][1]);
    }
  }
  for (int i = 1; i <= n; i++) {
    if (t) {
      if (f[i][0] > f[i][1]) {
        l += t;
      } else {
        r += t;
      }
      t = 0;
    }
    if (a[i] == '+') {
      t += b[i];
    } else {
      t += l * (b[i] - 1);
    }
    if (c[i] == '+') {
      t += d[i];
    } else {
      t += r * (d[i] - 1);
    }
    // std::cerr << l << ' ' << r << ' ' << t << '\n';
  }
  std::cout << l + r + t << '\n';
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