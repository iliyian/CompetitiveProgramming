// date: 2024-07-24 15:06:15
// tag: 数学，模拟

#include <bits/stdc++.h>
#define int long long
// using namespace std;

int dis(int x, int y) {
  if (x > y) std::swap(x, y);
  for (int d = 0;; d++) {
    if ((y >> d) == x) {
      return d;
    }
  }
}

int lc(int x, int y) {
  int dx = std::__lg(x), dy = std::__lg(y);
  if (dx < dy) {
    std::swap(x, y);
    std::swap(dx, dy);
  }
  x >>= (dx - dy);
  while (x != y) {
    x >>= 1, y >>= 1;
  }
  return x;
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  bool f = false, g = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (a[i] != -1) {
      f = true;
    } else {
      g = true;
    }
  }
  if (!f) {
    for (int i = 1; i <= n; i++) {
      std::cout << (i & 1 ? 2 : 1) << ' ';
    }
    std::cout << '\n';
    return;
  }
  for (int i = 1; i <= n - 1; i++) {
    if (a[i] != -1 && a[i + 1] != -1 && a[i] != a[i + 1] / 2 && a[i + 1] != a[i] / 2) {
      std::cout << -1 << '\n';
      return;
    }
  }
  if (f && !g) {
    for (int i = 1; i <= n; i++) {
      std::cout << a[i] << " \n"[i == n];
    }
    return;
  }
  int l;
  for (int i = 1; i <= n; i++) {
    if (a[i] != -1) {
      for (int j = i - 1; j >= 1; j--) {
        a[j] = ((j - i) % 2 ? a[j + 1] * 2 : a[j + 1] / 2);
      }
      l = i;
      break;
    }
  }
  int prv = l;
  for (int i = l + 1; i <= n; i++) {
    if (a[i] != -1) {
      if (prv == i - 1) {
        prv = i;
        continue;
      }
      int x = a[prv], y = a[i], lca = lc(x, y);
      int d = dis(lca, x) + dis(lca, y);
      if (d > i - prv || (i - prv - d) % 2) {
        std::cout << -1 << '\n';
        return;
      }
      for (int j = prv + 1; j < i; j++) {
        if (j - prv > d) {
          a[j] = ((j - prv - d) % 2 ? a[j - 1] * 2 : a[j - 1] / 2);
        } else {
          a[j] = ((j - prv) <= dis(lca, x) ? x >> (j - prv) : y >> (d - (j - prv)));
        }
      }
      prv = i;
    }
  }
  for (int i = prv + 1; i <= n; i++) {
    a[i] = ((i - prv) % 2 ? a[i - 1] * 2 : a[i - 1] / 2);
  }
  for (int i = 1; i <= n; i++) {
    std::cout << a[i] << " \n"[i == n];
  }
}

int32_t main() {
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