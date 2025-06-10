#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, k;
  std::cin >> n >> k;
  std::string str;
  std::cin >> str;
  auto rev = str;
  std::reverse(rev.begin(), rev.end());
  if (str < rev) {
    std::cout << "YES\n";
    return;
  }
  for (int i = 1; i < str.size(); i++) {
    if (str[i] != str[0]) {
      if (k) {
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
      return;
    }
  }
  std::cout << "NO\n";
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