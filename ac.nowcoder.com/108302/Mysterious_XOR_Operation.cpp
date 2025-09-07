#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    for (int j = 1; j < 30; j++) {
      
    }
  }
  std::array<std::array<int, 30>, 2> cnt, s;
  std::ranges::fill(cnt[0], 0);
  std::ranges::fill(cnt[1], 0);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int c = 0;
    for (int j = 0; j < 30; j++) {
      int x = a[i
    }
  }
  std::cout << ans << '\n';
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