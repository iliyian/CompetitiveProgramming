#include <bits/stdc++.h>
#define int long long

// 2548280139,279757372 -> mt19937_64
// 877771175 -> mt19937

using u64 = unsigned long long;
using u32 = unsigned long long;

void solve() {
  std::mt19937 rd(std::random_device{}());
  for (int i = 1;; i++) {
    u32 seed = rd();
    // std::cout << i << ' ' << seed << ": ";
    std::mt19937_64 mt(seed);
    int v = mt() % 100000000;
    if (v == 20250601) {
      std::cout << "YES\n";
      std::cout << seed << '\n';
      break;
    } else {
      // std::cout << "NO " << v << '\n';
    }
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