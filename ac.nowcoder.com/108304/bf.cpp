#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  int ans = 0;
  for (int l = 1; l <= n; l++) {
    for (int r = l; r <= n; r++) {
      int mn = a[l];
      std::set<int> s;
      for (int i = l; i <= r; i++) {
        mn = std::min(mn, a[i]);
        s.insert(a[i]);
      }
      int mex = mn + 1;
      while (s.count(mex)) mex++;
      ans += mex;
    }
  }
  std::cout << ans << '\n';
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