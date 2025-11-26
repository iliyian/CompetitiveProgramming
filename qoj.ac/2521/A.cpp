#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end(), std::greater<>());
  for (int i = 1; i <= n; i++) {
    a[i] += a[i - 1];
  }
  int j = 1, c = 0, ans = LLONG_MAX;
  for (int i = 1;; i++) {
    if (i > a[j - 1]) {
      j++;
      c++;
    }
    if ((i - c) / k + c >= n) {
      std::cout << i << '\n';
      return;
    }
  }
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