// date: 2024-07-15 14:27:47
// tag: 构造，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  if (n == 1) {
    std::cout << "a\n";
  } else if (n == 2) {
    std::cout << "ab\n";
  } else 
  for (int i = 1; i <= n; i++) {
    if (n % i) {
      for (int j = 0; j < n; j++) {
        std::cout << char('a' + j % i);
      }
      std::cout << '\n';
      return;
    }
  }
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}