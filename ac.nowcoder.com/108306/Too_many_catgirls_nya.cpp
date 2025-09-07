#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::string str;
  std::getline(std::cin, str);
  std::cout << n << " nya\n";
  for (int i = 1; i <= n; i++) {
    std::getline(std::cin, str);
    std::cout << str << " nya\n";
  }
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