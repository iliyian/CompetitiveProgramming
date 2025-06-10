#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int sum = 0;
  if (k == 1) {
    sum = a[1] + a[n];
    for (int i = 2; i <= n - 1; i++) {
      sum = std::max({a[1] + a[i], a[n] + a[i], sum});
    }
  } else {
    std::sort(a.begin() + 1, a.end());
    for (int i = n; i >= n - k; i--) {
      sum += a[i];
    }
  }
  std::cout << sum << '\n';
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