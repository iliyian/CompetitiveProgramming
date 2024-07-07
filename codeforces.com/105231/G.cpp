// date: 2024-07-01 21:59:24
// tag: 数论，暴力·

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int a;
    char b;
    std::cin >> a >> b;
    ans = (ans + a * (b == 'A' ? 10 : b - '0') % 5) % 5;
  }
  std::cout<< (ans % 5 ? "No" : "Yes") << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("G.in", "r", stdin);
  freopen("G.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}