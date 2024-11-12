#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (auto &i : a) {
    std::cin >> i;
  }
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());
  for (auto i : a) {
    if (i % 2 == 0) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
  for (auto i : a) {
    if (i % 2 == 1) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
  for (auto i : a) {
    if (i % 3 == 0) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
  for (auto i : a) {
    if (i % 10 == 5) {
      std::cout << i << ' ';
    }
  }
  std::cout << '\n';
}

signed main() {
  int t = 1;
  // std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}