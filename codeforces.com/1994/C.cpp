// date: 2024-07-30 16:25:40
// tag: 二分

#include <algorithm>
#include <bits/stdc++.h>
#define int long long
// using namespace std;

void solve() {
  int n, x;
  std::cin >> n >> x;
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    a[i] += a[i - 1];
  }
  std::vector<int> f(n + 2);
  int ans = 0;
  for (int i = n; i >= 0; i--) {
    int j = std::upper_bound(a.begin(), a.end(), a[i] + x) - a.begin();
    f[i] = f[j] + j - i - 1;
    ans += f[i];
  }
  std::cout << ans << '\n';
}

signed main() {
  std::cin.tie(nullptr)->sync_with_stdio(false);

  freopen("C.in", "r", stdin);
  freopen("C.out", "w", stdout);

  int _;
  std::cin >> _;

  while (_--) {
    solve();
  }

  return 0;
}