#include <bits/stdc++.h>
#define int long long

void solve() {
  int x;
  std::cin >> x;
  std::multiset<int> s;
  for (int i = 0; i < 3; i++) s.insert(0);
  int ans = 0;
  while (1) {
    if (*s.begin() == x && *s.rbegin() == x) break;
    s.erase(s.begin());
    s.insert(std::min(x, *s.begin() * 2 + 1));
    ans++;
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