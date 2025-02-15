#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int x;
  std::cin >> x;
  a[n] = std::max(a[n], x - a[n]);
  for (int i = n - 1; i >= 1; i--) {
    if (a[i] > a[i + 1] && x - a[i] > a[i + 1]) {
      std::cout << "NO\n";
      return;
    }
    if (a[i] <= a[i + 1] && x - a[i] <= a[i + 1]) {
      a[i] = std::max(a[i], x - a[i]);
      continue;
    }
    if (x - a[i] <= a[i + 1]) {
      a[i] = x - a[i];
    }
  }
  std::cout << "YES\n";
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