#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int cnt = 0;
  bool f = false;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    f |= !a[i];
    if (a[i] != a[i - 1]) {
      cnt++;
    }
  }
  if (!f) {
    std::cout << "YES\n";
    return;
  }
  for (int i = 2; i <= n; i++) {
    if (!a[i] && !a[i - 1]) {
      std::cout << "YES\n";
      return;
    }
  }
  // }
  // if (a[1] == 1) {
  //   if (cnt % 2 == 1) {
  //     std::cout << "YES\n";
  //     return;
  //   }
  // } else if (!cnt) {
  //   std::cout << "YES\n";
  //   return;
  // }
  std::cout << "NO\n";
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