#include <bits/stdc++.h>
#define int long long

void solve() {
  int T, S, t;
  std::cin >> T >> S >> t;
  if (S == 1 && T > 35 && t >= 33) {
    std::cout << "Bu Tie\n";
    std::cout << T << '\n';
    return;
  }
  if (S == 0 && T > 35 && t >= 33) {
    std::cout << "Shi Nei\n";
    std::cout << T << '\n';
    return;
  }
  if (S == 1) {
    std::cout << "Bu Re\n";
    std::cout << t << '\n';
    return;
  }
  std::cout << "Shu Shi\n";
  std::cout << t << '\n';
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