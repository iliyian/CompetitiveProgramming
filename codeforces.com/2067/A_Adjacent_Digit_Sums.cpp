#include <bits/stdc++.h>
#define int long long

void solve() {
  int a, b;
  std::cin >> a >> b;
  if (b <= a + 1 && (a + 1 - b) % 9 == 0) {
    std::cout << "Yes\n";
    return;
  }
  std::cout << "No\n";
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