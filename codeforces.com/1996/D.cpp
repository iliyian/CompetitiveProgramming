// date: 2024-07-27 10:27:21
// tag: 暴力，数学

#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, x;
  std::cin >> n >> x;
  int ans = 0;
  for (int a = 1; a <= n; a++) {
    for (int b = 1; b <= n / a; b++) {
      int c = std::max<int>(0, std::min(x - a - b, (n - a * b) / (a + b)));
      ans += c;
    }
  }
  std::cout << ans << '\n';
}

int32_t main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("D.in", "r", stdin);
  freopen("D.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}