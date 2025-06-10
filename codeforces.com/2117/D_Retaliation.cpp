#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  auto check = [&]() {
    for (int i = 2; i <= n; i++) {
      if (a[i] - a[i - 1] != a[2] - a[1]) {
        return false;
      }
    }
    if (a[1] > a[2]) return false;
    if ((a[1] - (a[2] - a[1])) < 0) return false;
    if ((a[1] - (a[2] - a[1])) % (n + 1)) return false;
    return true;
  };
  if (check()) {
    std::cout << "YES\n";
    return;
  }
  std::reverse(a.begin() + 1, a.end());
  if (check()) {
    std::cout << "YES\n";
    return;
  }
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