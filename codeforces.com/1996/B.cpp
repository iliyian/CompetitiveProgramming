#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  char ch;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char ch;
      std::cin >> ch;
      if (i % k == 0 && j % k == 0) {
        std::cout << ch;
      }
    }
    if (i % k == 0) {
      std::cout << '\n';
    }
  }
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("B.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}