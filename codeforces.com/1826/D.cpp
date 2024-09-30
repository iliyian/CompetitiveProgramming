// date: 2024-07-18 15:15:34
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 2), L(n + 2, LLONG_MIN), R(n + 2, LLONG_MIN);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    L[i] = std::max(L[i - 1], a[i] + i);
  }
  for (int i = n; i >= 1; i--) {
    R[i] = std::max(R[i + 1], a[i] - i);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, L[i - 1] + R[i + 1] + a[i]);
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}