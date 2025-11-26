#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  std::vector<std::vector<int>> r(1001);
  for (int n = 1; n <= 1000; n++) {
    int ans = 0;
    for (int m = 1; m <= n; m++) {
      auto calc = [&](int m) {
        int ans = 0;
        while (m) {
          ans += m % 10;
          m /= 10;
        }
        return ans;
      };
      if (n % m == calc(m)) {
        ans++;
        r[m].push_back(n);
      }
    }
  }
  for (int i = 0; i < 1001; i++) {
    std::cout << i << ": ";
    if (!r[i].empty()) {
      std::cout << r[i].front() - i << ' ';
    }
    for (int j : r[i]) {
      std::cout << j << ' ';
    }
    std::cout << '\n';
  }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}