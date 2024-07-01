// date: 2024-06-30 18:17:15
// tag: 递推

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + m + 2), b(n + m + 2);
  for (int i = 1; i <= n + m + 1; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n + m + 1; i++) {
    std::cin >> b[i];
  }
  std::vector<int> id(n + m + 2, -1);
  std::vector<int> f(n + m + 2);
  int x = 0, y = 0, res = 0;
  for (int i = 1; i <= n + m; i++) {
    if (x == n) {
      id[i] = 1;
    } else if (y == m) {
      id[i] = 0;
    } else if (a[i] > b[i]) {
      id[i] = 0;
    } else {
      id[i] = 1;
    }
    res += id[i] ? b[i] : a[i];
    (id[i] ? y : x)++;
  }

  x = n + m + 1, y = n + m + 1;
  f[n + m + 1] = 0;
  for (int i = n + m; i >= 1; i--) {
    if (!id[i]) {
      if (x != n + m + 1) {
        f[i] = f[x] - b[x] + a[x];
      } else {
        f[i] = a[x];
      }
    } else {
      if (y != n + m + 1) {
        f[i] = f[y] - a[y] + b[y];
      } else {
        f[i] = b[y];
      }
    }

    if (a[i] > b[i] && id[i]) {
      x = i;
    } else if (a[i] < b[i] && !id[i]) {
      y = i;
    }
  }

  for (int i = 1; i <= n + m; i++) {
    std::cout << res - (id[i] ? b[i] : a[i]) + f[i] << ' ';
  }
  std::cout << res << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}