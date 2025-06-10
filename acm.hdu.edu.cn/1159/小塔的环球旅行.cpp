#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::string str, t;
    std::cin >> str >> t;
    int h = std::stoll(str.substr(0, 2));
    int d = std::stoll(t);
    h = (h + d + 24) % 24;
    if (h < 10) std::cout << 0;
    std::cout << h << ":" << str.substr(3, 2) << '\n';
  }
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