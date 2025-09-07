#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  std::map<int, std::vector<int>> pos;
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    pos[a[i]].push_back(i);
  }
  std::vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    std::cin >> b[i];
    for (int j : pos[b[i]]) {
      ans[(i - j + n) % n]++;
    }
  }
  int mx = 0;
  for (int i = 1; i < n; i++) {
    if (ans[i] > ans[mx]) {
      mx = i;
    }
  }
  std::cout << ans[mx] << ' ' << mx << '\n';
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