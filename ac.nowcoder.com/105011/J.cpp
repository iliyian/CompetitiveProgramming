#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int x = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    x ^= a[i];
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] != 1) {
      std::cout << (x ? "Akie" : "Jiuhui") << '\n';
      return;
    }
  }
  std::cout << (x ? "Jiuhui" : "Akie") << '\n';
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