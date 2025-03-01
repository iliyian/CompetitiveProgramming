// date: 2025-02-23 20:27:17
// tag: 暴力，先按照必要条件进行有效剪枝

#include <bits/stdc++.h>
#define int long long

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::string str;
  std::cin >> str;
  int cA = 0, cB = 0;
  for (int i = 0; i < n; i++) {
    if (str[i] == 'A') cA++;
    else cB++;
    if (std::max(cA, cB) >= m && std::abs(cA - cB) >= 2) {
      std::cout << "Yes\n";
      std::cout << i + 1 << '\n';
      return;
    }
  }
  int t = std::max(0ll, m / std::max(cA, cB) - 1);
  int c0 = cA * t, c1 = cB * t;
  for (int i = 0; i < 10 * n; i++) {
    c0 += str[i % n] == 'A';
    c1 += str[i % n] == 'B';
    if (std::max(c0, c1) >= m && std::abs(c0 - c1) >= 2) {
      std::cout << "Yes\n";
      std::cout << i + 1 + t * n << '\n';
      return;
    }
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