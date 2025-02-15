// date: 2025-01-27 20:30:03
// tag: 贪心，模拟

#include <bits/stdc++.h>
#define int long long

void solve() {
  std::string s, t;
  std::cin >> s >> t;
  int n = s.size(), ans = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      int j = i;
      if (i && s[i - 1] == s[i]) {
        std::cout << -1 << '\n';
        return;
      }
      while (j + 1 < n && t[j + 1] == t[i]) j++;
      int cnt = j - i + 1;
      int k = i, cur = 0, c = 0;
      while (k + 1 < n && cur < cnt) {
        cur += s[++k] == t[i];
        c += (s[k] != s[k - 1] && s[k] == t[i]);
      }
      ans += c;
      if (cur < cnt || (k != n - 1 && s[k + 1] == s[k])) {
        std::cout << -1 << '\n';
        return;
      }
      for (int u = i; u <= k; u++) {
        s[u] = t[i] ^ (u > j);
      }
    }
  }
  std::cout << ans << '\n';
  // std::cerr << s << '\n' << t << '\n';
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