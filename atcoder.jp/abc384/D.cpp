#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, s;
  std::cin >> n >> s;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
    a[i] += a[i - 1];
  }
  // for (int t = 1; t <= 20; t++) {
  //   int tmp = s;
  //   s = s % (sum * t);
    for (int i = n; i >= 0; i--) {
      int rest = (s - (a[n] - a[i])) % sum;
      // if (rest < 0) break;
      auto p = std::lower_bound(a.begin(), a.end(), rest);
      // std::cout << rest << ' ' << *p << ' ' << p - a.begin() << '\n';
      if (*p == rest) {
        std::cout << "Yes\n";
        return;
      }
    }
    // s = tmp;
  // }
  std::cout << "No\n";
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
