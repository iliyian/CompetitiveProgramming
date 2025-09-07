// date: 2025-07-23 15:36:05
// tag: 某数位dp

#include <bits/stdc++.h>
#define int long long

int C[63][63] {};

int check(int x, int j) {
  int ans = 0;
  for (int i = 0; i < x; i++) {
    ans += __builtin_popcountll(i) == j;
  }
  return ans;
}

int get(int x, int j) {
  if (x <= 1 || j == 0) return 0;
  int p = 63 - __builtin_clzll(x), ans = 0;
  return C[p][j] + get(x ^ (1ll << p), j - 1) + (j == 1 && __builtin_popcountll(x) > j);
}

void solve() {
  int x, y, k;
  std::cin >> x >> y >> k;
  if (y == 0) {
    if (k == 1) {
      std::cout << 0 << '\n';
    } else {
      std::cout << -1 << '\n';
    }
    return;
  }
  int l = 1, r = x + 1, ans = 0;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (get(mid, y) >= k) r = mid - 1, ans = mid;
    else l = mid + 1;
  }
  std::cout << ans - 1 << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  C[0][0] = 1;
  for (int i = 1; i <= 62; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j <= i - 1; j++) {
      C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
    }
  }

  for (int i = 0; i <= 128; i++) {
    for (int j = 1; j <= 3; j++) {
      // std::cout << i << ' ' << j << ' ' << get(i + 1, j) << ' ' << check(i, j) << '\n';
      if (get(i, j) != check(i, j)) {
        std::cout << i << ' ' << j << ' ' << get(i, j) << ' ' << check(i, j) << '\n';
      }
    }
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}