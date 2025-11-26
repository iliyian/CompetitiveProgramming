#include <bits/stdc++.h>
#define int long long

// 1 4 21 120 697 4060

void solve() {
  
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<int> f(101);
  f[1] = 3, f[2] = 20;
  for (int i = 3; i <= 100; i++) {
    f[i] = 6 * f[i - 1] - f[i - 2] + 2;
  }
  for (int i = 1; i <= 100; i++) {
    std::cerr << i << ": " << f[i] << '\n';
  }

  int prv = 1;
  for (int L = 1; L <= 4060; L++) {
    for (int n = L;; n++) {
      int l = 1, r = n, ans = -1;
      while (l <= r) {
        int mid = (l + r) / 2;
        if (mid * (mid + 1) * 2 <= n * (n + 1)) l = mid + 1, ans = mid;
        else r = mid - 1;
      }
      if (ans * (ans + 1) * 2 == n * (n + 1)) {
        if (n != prv) {
          std::cout << n << ' ' << L << ' ' << n - 6 * prv << '\n';
          prv = n;
        }
        break;
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