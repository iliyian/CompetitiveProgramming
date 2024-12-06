#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    sum += a[i];
  }
  if (sum % n) {
    std::cout << "NO\n";
    return;
  }
  sum /= n;
  for (int i = 1; i <= n - 2; i++) {
    if (a[i] != sum) {
      int t = sum - a[i];
      a[i] += t;
      a[i + 2] -= t;
    }
  }
  if (a[n] != sum || a[n - 1] != sum) {
    std::cout << "NO\n";
  } else {
    std::cout << "YES\n";
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}