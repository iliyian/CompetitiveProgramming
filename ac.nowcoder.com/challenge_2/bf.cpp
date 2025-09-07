#include <bits/stdc++.h>
#define int long long


bool check(int x) {
  auto s = std::to_string(x);
  if (s.size() % 2 == 0) return false;
  for (int i = 0; i <= (int)s.size() - i - 1; i++) {
    if (s[i] != s[s.size() - i - 1]) {
      return false;
    }
    if (i) {
      if (((s[i - 1] - '0') & 1) == ((s[i] - '0') & 1)) {
        return false;
      }
    }
  }
  return true;
}

void solve() {
  int l, r;
  std::cin >> l >> r;
  int ans = 0;
  for (int i = l; i <= r; i++) {
    if (check(i)) {
      ans++;
      std::cerr << i << '\n';
    }
  }
  std::cout << ans << '\n';
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