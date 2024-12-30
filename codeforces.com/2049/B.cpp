#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::string str;
  std::cin >> n >> str;
  str = '#' + str;
  if (!str.contains('s') || !str.contains('p')) {
    std::cout << "YES\n";
    return;
  }
  int p = 0, s = 0;
  for (int i = 1; i <= n; i++) {
    if (str[i] == 'p') {
      // p = i;
      if (!p) p = i;
    }
    if (str[i] == 's') {
      // if (!s) s = i;
      s = i;
      if (p) {
        std::cout << "NO\n";
        return;
      }
    }
  }
  assert(p && s);
  if (s > 1 && p < n) {
    std::cout << "NO\n";
    return;
  }
  std::cout << "YES\n";
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