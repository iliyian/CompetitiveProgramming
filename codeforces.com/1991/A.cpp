#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int mx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    if (i & 1) {
      mx = std::max(mx, x);
    }
  }
  std::cout << mx << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("A.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}