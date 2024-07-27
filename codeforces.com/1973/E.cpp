// date: 2024-07-27 12:49:55
// tag: 贪心

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int r = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  if (std::is_sorted(a.begin() + 1, a.end())) {
    std::cout << (n * 2) * (n * 2 + 1) / 2 << '\n';
    return;
  }
  int L = 0, R = n;
  for (int i = 1; i <= n; i++) {
    if (a[i] != i) {
      R = i;
      if (r == 0) r = a[i] + i;
      else if (r != a[i] + i) r = -1;
    }
  }
  for (int i = n; i >= 1; i--) {
    if (a[i] != i) {
      L = i;
    }
  }
  R++, L += n;

  // int ans = (n * 2 - R + 1) * L - (L >= R);
  int ans = r > 0;
  for (int i = R; i <= n * 2; i++) {
    ans += std::min(i - 1, L);
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("E.in", "r", stdin);
  freopen("E.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}