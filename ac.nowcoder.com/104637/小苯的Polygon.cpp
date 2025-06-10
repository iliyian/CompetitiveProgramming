#include <bits/stdc++.h>
#define int long long

constexpr int N = 1e4;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  std::sort(a.begin() + 1, a.end());
  int ans = LLONG_MAX / 3;
  for (int i = 3; i <= n; i++) {
    std::bitset<N + 1> f;
    f[0] = 1;
    for (int j = 1; j < i; j++) {
      f |= f << a[j];
    }
    for (int j = a[i] + 1; j <= N; j++) {
      if (f[j]) {
        ans = std::min(ans, j + a[i]);
        break;
      }
    }
  }
  std::cout << (ans == LLONG_MAX / 3 ? -1 : ans) << '\n';
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