#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;
  std::cin >> n >> k;
  if (n == 1) {
    std::cout << 1 << '\n' << 1 << '\n';
    return;
  }
  if (k == 1 || k == n) {
    std::cout << -1 << '\n';
    return;
  }
  if (k & 1 ^ 1) {
    std::cout << 3 << '\n';
    std::cout << 1 << ' ' << k << ' ' << k + 1 << '\n';
    return;
  }
  std::cout << 5 << '\n';
  std::cout << 1 << ' ' << k - 1 << ' ' << k << ' ' << k + 1 << ' ' << k + 2 << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}