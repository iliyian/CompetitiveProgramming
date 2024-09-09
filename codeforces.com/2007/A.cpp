#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int l, r;
  std::cin >> l >> r;
  int ans = 0;
  for (int i = l + (l & 1 ^ 1); i + 2 <= r; i += 2) {
    if (std::gcd(i, i + 2) == 1) {
      ans++;
      i += 2;
    }
  }
  std::cout << ans << '\n';
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