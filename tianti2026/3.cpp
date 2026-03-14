#include <bits/stdc++.h>
#define int long long

void solve() {
  int H, h1, h2;
  std::cin >> H >> h1 >> h2;
  std::cout << H << '\n';
  if (H < h1) {
    std::cout << "Bu Kan\n";
  } else if (H < h2) {
    std::cout << "Zhe Gua Bao Shu Ma\n";
  } else {
    std::cout << "Chi Gua\n";
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int t = 1;
  // std::cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}