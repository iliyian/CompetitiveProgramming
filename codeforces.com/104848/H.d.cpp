#include <bits/stdc++.h>
#define int long long

std::mt19937 rd(std::random_device{}());

void solve() {
  int n = 1e5;
  std::cout << n << '\n';
  std::string str = "MCXI";
  for (int i = 0; i < n; i++) {
    std::cout << str[rd() % 4];
  }
  std::cout << '\n';
}

signed main() {
  freopen("H.in", "w", stdout);
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}