#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> a(n + 1);
  int mn = INT_MAX;;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    mn &= a[i];
  }
  if (mn > 0) {
    std::cout << 1 << '\n';
    return;
  }
  int x = INT_MAX;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if ((x & a[i]) == mn) {
      ans++;
      x = INT_MAX;
    } else {
      x &= a[i];
    }
  }
  std::cout << ans << '\n';
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