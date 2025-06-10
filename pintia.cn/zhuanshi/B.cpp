#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  int c = std::min(a, b);
  std::cout << c << '\n';
  if (c <= 20) {
    std::cout << "XianHua\n";
  } else if (c <= 40) {
    std::cout << "XiangXun\n";
  } else if (c <= 60) {
    std::cout << "BaoWenBei\n";
  } else {
    std::cout << "HunShaZhao\n";
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