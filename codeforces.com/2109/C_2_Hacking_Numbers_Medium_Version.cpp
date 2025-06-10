#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans;
  std::cout << "mul 999999999" << std::endl;
  std::cin >> ans;
  std::cout << "digit" << std::endl;
  std::cin >> ans;
  if (n != 81) {
    std::cout << "add " << n - 81 << std::endl;
    std::cin >> ans;
  }
  std::cout << "! " << std::endl;
  std::cin >> ans;
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