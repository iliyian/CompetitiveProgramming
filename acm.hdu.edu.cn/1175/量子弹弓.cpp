#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    s += a[i];
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      std::cout << "NO\n";
      return;
    }
  }
  std::cout << (s >= 2 * (n - 1) ? "YES" : "NO") << '\n';
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