#include <bits/stdc++.h>
#define int long long

void solve() {
  int n;
  int pos = -1, i = 0;
  while (std::cin >> n) {
    ++i;
    if (n == 520 && pos == -1) {
      pos = i;
    }
  }
  std::cout << pos << '\n';
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