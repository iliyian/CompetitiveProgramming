#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1), b(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    if ((a[i] ^ a[i + 1]) != b[i] && (a[i] ^ b[i + 1]) != b[i] && a[i] != b[i]) {
      std::cout << "NO\n";
      return;
    }
  }
  if (a[n] != b[n]) {
    std::cout << "NO\n";
    return;
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