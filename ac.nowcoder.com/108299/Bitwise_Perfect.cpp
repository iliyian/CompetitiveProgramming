#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  std::set<int> s;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    int hi = 63 - __builtin_clzll(a[i]);
    if (s.count(hi)) {
      std::cout << "NO\n";
      return;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if ((a[i] ^ a[j]) <= std::max(a[i], a[j])) { // 不可能等于
        std::cout << "NO\n";
        return;
      }
    }
  }
  std::cout << "YES\n";
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  // for (int a = 1; a <= 10; a++) {
  //   for (int b = 1; b <= 10; b++) {
  //     if ((1 << a) + (1 << b) > (1 << (a ^ b))) {
  //       std::cout << a << ' ' << b << '\n';
  //     }
  //   }
  // }

  int t = 1;
  std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}