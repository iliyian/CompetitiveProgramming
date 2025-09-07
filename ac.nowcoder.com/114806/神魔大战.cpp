#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    a[i] = a[i];
    b[i] = a[i] - b[i];
  }
  std::vector<int> f(20001, LLONG_MIN);
  f[10000] = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] >= 0) {
      for (int j = 20000; j >= b[i]; j--) {
        f[j] = std::max(f[j], f[j - b[i]] + a[i]);
      }
    } else {
      for (int j = 0; j - b[i] <= 20000; j++) {
        f[j] = std::max(f[j], f[j - b[i]] + a[i]);
      }
    }
  }
  std::cout << f[10000] << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}