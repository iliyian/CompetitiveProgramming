#include <bits/stdc++.h>

int main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int n, ans = 0;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    ans += std::abs(x);
  }
  std::cout << ans << '\n';
  return 0;
}