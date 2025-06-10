#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  int ans;
  std::cout << "digit" << std::endl;
  std::cin >> ans;
  std::cout << "digit" << std::endl;
  std::cin >> ans;
  for (int i = 8; i >= 1; i /= 2) {
    std::cout << "add " << -i << std::endl;
    std::cin >> ans;
  }
  std::cout << "add " << n - 1 << std::endl;
  std::cin >> ans;
  std::cout << "!" << std::endl;
  std::cin >> ans;
  // assert(ans == 1);
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