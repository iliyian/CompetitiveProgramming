// date: 2025-05-08 17:38:33
// tag: 啊，结论永远是那么清晰，那么明确，只是沿途的思想混沌不清。

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, x, y;
  std::cin >> n >> x >> y;
  std::vector<int> a(x + 1);
  for (int i = 1; i <= x; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  a.push_back(a[1] + n);
  std::vector<int> b;
  int ans = x - 2;
  for (int i = 2; i <= x + 1; i++) {
    if (a[i] - a[i - 1] == 2) {
      ans++;
    } else if (a[i] - a[i - 1] > 2) {
      b.push_back(a[i] - a[i - 1]);
    }
  }
  std::sort(b.begin(), b.end(), [&](const int &x, const int &y) {
    if (x % 2 != y % 2) {
      return x % 2 < y % 2;
    }
    return x < y;
  });
  for (int i : b) {
    int r = (i - 1) / 2;
    if (y >= r) {
      ans += r + r;
      if (i % 2 == 0) {
        ans++;
      }
      y -= r;
    } else {
      ans += y + y;
      break;
    }
  }
  std::cout << std::max(ans, 0ll) << '\n';
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